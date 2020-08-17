#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(str1.size()) i = 0; i != size; ++i)
		if (str1[i] != str2[i])
			return false;
}

int main(void)
{
	bool flag;
	if (flag=str_subrange("hello", "hel"))
		cout << "hello world" << endl;
	else
		cout << "fxck" << endl;

	return 0;
}
