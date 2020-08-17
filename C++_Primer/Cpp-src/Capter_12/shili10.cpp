#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
	string str1("hello world"), str2(" show me the world");
	str1 += str2;
	char* pcarr = new char[str1.size()];
	for (size_t i = 0; i < str1.size(); ++i)
	{
		pcarr[i] = str1[i];
		cout << pcarr[i];
	}
	cout << endl;
	delete[] pcarr;

	return 0;
}
