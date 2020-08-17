#include<iostream>
#include<string>
#include<stack>
using namespace::std;

class Test;
ostream& operator<<(ostream& os, const Test& item);

class Test {
	friend ostream& operator<<(ostream& os, const Test& item);
public:
	Test(int val):value(val){}

private:
	int value;
};

ostream& operator<<(ostream& os, const Test& item)
{
	return os << item.value;
}


int main(void)
{
	stack<Test> testStack;
	for (size_t i = 0; i < 10; ++i)
		testStack.push(i);
	while (!testStack.empty())
	{
		cout << testStack.top() << ' ';
		testStack.pop();
	}

	return 0;
}
