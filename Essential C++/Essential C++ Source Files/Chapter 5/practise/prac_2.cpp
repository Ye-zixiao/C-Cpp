#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef string elemType;

class Stack												//���崿�������
{
public:
	virtual ~Stack(){}
	virtual bool pop(elemType&) = 0;
	virtual bool push(const elemType&) = 0;
	virtual bool peek(int index, elemType&) = 0;

	virtual int top() const = 0;
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual bool full() const = 0;

	virtual void print(ostream &os= cout) const = 0;

};

ostream& operator<<(ostream& os, const Stack& rhs)		//������������������
{
	rhs.print();
	return os;
}

class LIFO_Stack :public Stack
{
public:
	LIFO_Stack(int capacity = 0)
		:_top(0)
	{
		if (capacity)
			_stack.reserve(capacity);				//reserve��������vector�Ĵ�С�����ɲ�������ʾ��Ԫ�ظ���
	}

	bool pop(elemType& elem);
	bool push(const elemType& elem);
	bool peek(int, elemType&) { return false; }

	int size() const { return _stack.size(); }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
	int top() const { return _top; }

	void print(ostream& os) const;

private:
	vector<elemType> _stack;
	int _top;				//ָ��ջ��λ��
};

bool LIFO_Stack::
pop(elemType& elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool LIFO_Stack::
push(const elemType& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

void LIFO_Stack::
print(ostream& os) const
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(),//const_reverse_iterator���������Ե������vector����
		rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
}


class Peekback_Stack :public Stack
{
public:
	Peekback_Stack(int capacity = 0)
		:_top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}

	bool pop(elemType& elem);
	bool push(const elemType& elem);
	bool peek(int, elemType&);						//peek�����ڲ��ı�stackԪ�ص�ǰ���£������κ�һ��Ԫ��

	int size() const { return _stack.size(); }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
	int top() const { return _top; }

	void print(ostream& os) const;

private:
	vector<elemType> _stack;
	int _top;
};

void Peekback_Stack::
print(ostream& os) const
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(),
		rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
}

bool Peekback_Stack::
pop(elemType& elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Peekback_Stack::
push(const elemType& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

bool Peekback_Stack::
peek(int index, elemType& elem)
{
	if (empty())
		return false;
	if (index < 0 || index >= size())
		return false;

	elem = _stack[index];
	return true;
}

void peek(Stack& st, int index)				//ʹ�����⺯��չʾ����ָ��/���õĶ�̬����
{
	string t;
	if (st.peek(index, t))
		cout << "peek: " << t;
	else
		cout << "Peek failed!";
	cout << endl;
}


int main(void)
{
	LIFO_Stack st;
	string str;
	while (cin >> str && !st.full())
		st.push(str);

	cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
	peek(st, st.top() - 1);
	cout << st;

	Peekback_Stack pst;
	while (!st.empty())
	{
		string t;
		if (st.pop(t))
			pst.push(t);
	}

	cout << "About to call peek() with Peekback_Stack" << endl;
	peek(pst, pst.top() - 1);//����ջ��Ԫ�أ�topʵ���ϱ�ʾ��ջ�ĳ���
	cout << pst;

	return 0;
}
