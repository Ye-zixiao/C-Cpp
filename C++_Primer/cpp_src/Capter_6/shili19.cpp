#include<iostream>
#include<string>
using namespace::std;
/*
inline bool
isShorter(const string& str1, const string& str2)
{
	return str1.size() < str2.size();
}
*/

constexpr bool
isShorter(const string& str1,const string &str2)
{
    return str1.size()<str2.size();
}

int main(void)
{
	cout << (isShorter("hello", "worldith") ? "Shorter" : "Longer") << endl;

	return 0;
}
