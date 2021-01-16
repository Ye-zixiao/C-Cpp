#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef string elemType;

class Stack								//具象基类,能够实际产生类对象
{
public:
	Stack(int capacity = 0)
		:_top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}
	virtual ~Stack(){}

	bool push(elemType&);
	bool pop(elemType&);
	virtual bool peek(int index, elemType&) const { return false; }

	int size()const { return _stack.size(); }
	int top() const { return _top; }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }

	void print(ostream& os = cout) const;

protected:
	vector<elemType> _stack;
	int _top;
};

class Peekback_Stack :public Stack				/*由于具象基类已经完成了大多数的实现，所以具象基类的派生类只要
												实现基类中所提供的接口，给出自己的实现对基类进行覆盖即可。*/
{
public:
	Peekback_Stack(int capacity = 0)
		:Stack(0){}
	~Peekback_Stack(){}

	bool peek(int index, elemType&) const;

};

/*------------Stack的实现-------------------*/
bool Stack::
push(elemType& elem)
{
	if (!full())
	{
		_stack.push_back(elem);
		++_top;
		return true;
	}
	else
		return false;
}

bool Stack::
pop(elemType& elem)
{
	if (!empty())
	{
		elem = _stack[_top-- - 1];
		_stack.pop_back();
		return true;
	}
	else
		return false;
}

void Stack::
print(ostream& os) const
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(),
		rend = _stack.rend();
	while (rit != rend)
		cout << "\n\t" << *rit++ << ' ';
	cout << endl;
}


/*-----------------Peekback_Stack的实现--------------*/
bool Peekback_Stack::
peek(int index, elemType& elem) const
{
	if (empty())
		return false;
	if (index < 0 || index >= size())
		return false;
	elem = _stack[index];
	return true;
}

/*-----------------others-----------------*/
ostream& operator<<(ostream& os, const Stack& st)
{
	st.print(os);
	return os;
}

void peek(Stack& st, int index)
{
	string t;
	if (st.peek(index, t))
		cout << "peek: " << t;
	else
		cout << "Peek failed!";
	cout << endl;
}


/*---------------main函数--------------------*/
int main(void)
{
	Stack st;
	string str;
	while (cin >> str && !st.full())
		st.push(str);
	cout << "\n" << "About to call peek() with Stack" << endl;
	peek(st, st.top() - 1);
	cout << st << endl;

	Peekback_Stack st1;
	while (!st.empty())
	{
		string str1;
		if (st.pop(str1))
			st1.push(str1);
	}
	cout << "\n" << "About to call peek() with Peekback_Stack" << endl;
	peek(st1, st1.top() - 1);
	cout << st1 << endl;

	return 0;
}
