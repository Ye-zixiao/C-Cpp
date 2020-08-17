#include<iostream>
#include<string>
using namespace::std;

union MyUnion {
	int ivalue;
	double dvalue;
	string str;

	MyUnion():str(){}
	MyUnion(int v):ivalue(v){}
	MyUnion(double d):dvalue(d){}
	MyUnion(const string&s):str(s){}
	~MyUnion() { str.~basic_string(); }
};

int main(void)
{
	MyUnion item("hello world");
	cout << item.str << endl;
	item.str.~basic_string(); item.dvalue = 42.3;
	cout << item.dvalue << endl;
	new (&item.str) string("fuck!");
	//item.str = "hello";					//wrong
	//item.str(string("hello wrold"));		//wrong
	//item.str = string("fuck");			//wrong
	cout << item.str << endl;
	//item.str.~basic_string(); item.ivalue = 412;//也是有问题的
	//cout << item.ivalue << endl;

	return 0;
}
