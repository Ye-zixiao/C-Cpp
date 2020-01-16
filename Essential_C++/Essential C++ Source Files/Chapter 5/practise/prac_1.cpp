#include<iostream>
#include<vector>
using namespace std;

class Stack
{
public:
	Stack(int len=0);
	virtual ~Stack(){}

	virtual int pop() = 0;
	virtual bool push(int value) = 0;
	virtual int peek() const = 0;
	virtual void print() const = 0;

	int length() const { return size; }
	bool empty() const { return size == 0; }
	bool full() const { return size == 20; }

protected:
	int size;
	int peek_pos;

};

inline Stack::
Stack(int len)
	:size(len), peek_pos(len){}


class LIFO_Stack : public Stack
{
public:
	LIFO_Stack(int len=0)
		:Stack(len){}
	~LIFO_Stack(){}

	virtual int pop();
	virtual bool push(int value);
	virtual int peek() const;
	virtual void print() const;

protected:
	static vector<int> stack1;
};

int LIFO_Stack::
pop()
{
	if (empty())
	{
		cout << "No value in the stack" << endl;
		return 0;
	}
	--size;
	--peek_pos;

	return stack1[peek_pos - 1];
}

bool LIFO_Stack::
push(int value)
{
	if (full())
	{
		cout << "The stack is full" << endl;
		return false;
	}
	size++;
	peek_pos++;
	stack1.push_back(value);

	return true;
}

int LIFO_Stack::
peek() const
{
	if (empty())
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}
	else
		return stack1[peek_pos - 1];
}

void LIFO_Stack::
print() const
{
	if (empty())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	else
	{
		cout << "Following is the value member:";
		for (int i = 0; i < size; ++i)
		{
			if (i % 10 == 0)
				cout << endl;
			cout << stack1[i] << ' ';
		}
		cout << endl;
	}
}

vector<int> LIFO_Stack::stack1;

int main(void)
{
	LIFO_Stack st1;
	cout << st1.length() << endl;
	st1.push(1);
	st1.push(9);
	st1.push(10);
	st1.push(12);
	st1.print();
	cout << st1.length() << endl;

	cout << endl;
	st1.pop();
	st1.pop();
	cout << st1.peek() << endl;
	st1.print();

	return 0;
}
