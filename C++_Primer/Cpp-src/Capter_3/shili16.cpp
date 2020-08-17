#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
	string str = "hello world";
	if (str.begin() != str.end())
	{
		auto begin_iter = str.begin();
		//string::iterator begin_iter = str.begin();
		*begin_iter = toupper(*begin_iter);
	}

	cout << str << endl;

	return 0;
}
