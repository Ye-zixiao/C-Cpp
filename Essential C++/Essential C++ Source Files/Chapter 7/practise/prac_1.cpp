#include<iostream>
#include<vector>
#include<string>
#include<exception>
#include<sstream>
using namespace std;

typedef string elemType;


/*-------------------�̳�exception������������صı�׼�쳣��------------------------*/
class Full_Error :public exception
{
public:
	Full_Error(int stack_len, int max_size)
		:_stack_len(stack_len), _max_size(max_size) {}

	int stack_current_size(void) const { return _stack_len; }
	int max_stack_size(void) const { return _max_size; }

	virtual const char* what(void) const throw();

private:
	int _stack_len;
	int _max_size;
};

const char* Full_Error::
what(void) const throw()
{
	ostringstream ex_msg;
	static string msg;										/*static���ڵ��������ڣ����û��static�ؼ��ֵĴ��ڣ�һ���ó�Ա����������ϣ�string��
															�ڴ�ռ䣨���ڴ��е�ջ�����ͷź󣬺������ص�const char*�ͻ�ָ��һƬ�������򣬴�ʱ�ͻ�
															������������*/

	ex_msg << "Internal error: current stack size "
		<< "has touch the maximum bound " << _max_size;
	msg = ex_msg.str();

	return msg.c_str();
}

class NoMem :public exception
{
public:
	NoMem() {}

	const char* what(void) const throw();

private:
};

const char* NoMem::
what(void) const throw()
{
	ostringstream ex_msg;
	static string msg;

	ex_msg << "Stack has no member!";
	msg = ex_msg.str();

	return msg.c_str();
}


class Stack										//�������,�ܹ�ʵ�ʲ��������
{
public:
	Stack(int capacity = 0)
		:_top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}
	virtual ~Stack() {}

	/*bool push(elemType&);
	bool pop(elemType&);*/
	void push(elemType&);						//ʹ���׳���׼�쳣������������ʾ��������
	void pop(elemType&);
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

class Peekback_Stack :public Stack				/*���ھ�������Ѿ�����˴������ʵ�֣����Ծ�������������ֻҪ
												ʵ�ֻ��������ṩ�Ľӿڣ������Լ���ʵ�ֶԻ�����и��Ǽ��ɡ�*/
{
public:
	Peekback_Stack(int capacity = 0)
		:Stack(0) {}
	~Peekback_Stack() {}

	bool peek(int index, elemType&) const;

};

/*------------Stack��ʵ��-------------------*/
/*bool Stack::
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
}*/


void Stack::
push(elemType& elem)
{
	try
	{
		if (full())
			throw Full_Error(_stack.size(), _stack.max_size());
		_stack.push_back(elem);
		++_top;
	}
	catch (exception & ex)
	{
		cerr << ex.what() << endl;
	}
}

void Stack::
pop(elemType& elem)
{
	try
	{
		if (empty())
			throw NoMem();
		elem = _stack[_top - 1];
		_stack.pop_back();
	}
	catch (exception & ex)
	{
		cerr << ex.what() << endl;
	}
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


/*-----------------Peekback_Stack��ʵ��--------------*/
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


/*---------------main����--------------------*/
int main(void)
{
	//Stack st;
	//string str;
	//while (cin >> str && !st.full())
	//	st.push(str);
	//cout << "\n" << "About to call peek() with Stack" << endl;
	//peek(st, st.top() - 1);
	//cout << st << endl;

	//Peekback_Stack st1;
	//while (!st.empty())
	//{
	//	string str1;
	//	if (st.pop(str1))
	//		st1.push(str1);
	//}
	//cout << "\n" << "About to call peek() with Peekback_Stack" << endl;
	//peek(st1, st1.top() - 1);
	//cout << st1 << endl;

	Stack st;
	string str, str_in;
	//cin >> str_in;
	//st.push(str_in);
	st.pop(str);
	cout << str << endl;

	return 0;
}
