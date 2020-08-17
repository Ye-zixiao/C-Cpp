#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

const string& shorterString(const string& str1, const string& str2)
{
	return (str1.size() < str2.size()) ? str1 : str2;
}

string& shorterString(string& str1, string& str2)
{
	auto& retString = shorterString(const_cast<const string&>(str1), const_cast<const string&>(str2));
	return const_cast<string&>(retString);
}

int main(void)
{
	string str1 = "hello", str2 = "yes";
	shorterString(str1, str2) = "world";
	cout << str1 << ' ' << str2 << endl;
	return 0;
}
