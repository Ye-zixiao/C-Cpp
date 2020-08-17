#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

class Test {
public:
	Test(){}
	string hello;
	size_t function(void)
	{
		return 10;
	}
};

int main(void)
{
	char test = 'q';
	cout << (~test<< 6) << endl;

	cout << sizeof(test) << endl;
	cout << sizeof(size_t) << endl;
	//cout << sizeof string << endl;这个不能在code：：blocks中运行，可能是编译器的问题
	cout << sizeof(string) << endl;
	string* pstr;
	cout << sizeof(*pstr) << endl;
	cout << sizeof pstr << endl;

	cout << "-----------------------------------" << endl;
	cout << sizeof Test::hello << endl;
	cout << sizeof(Test) << endl;

	return 0;
}
