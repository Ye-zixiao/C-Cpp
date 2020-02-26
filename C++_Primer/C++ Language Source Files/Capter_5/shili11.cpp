#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	string str1, str2;
	do
	{
		cout << "Input two strings:";
		cin >> str1 >> str2;
		cout << (str1.size() < str2.size() ? str1 : str2)
			<< "\nKeep input?(y/n)";
		cin >> str1;
	} while (tolower(str1[0]) != 'n');

	return 0;
}
