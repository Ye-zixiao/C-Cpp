#include<iostream>
#include<string>
#include<new>
using namespace::std;

int main(void)
{
	string* pstr = new string("hello world");
	pstr->~basic_string();

	new (pstr) string("hello");//定位new表达式
	cout << *pstr << endl;

	return 0;
}
