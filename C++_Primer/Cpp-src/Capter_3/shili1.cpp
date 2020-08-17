#include<iostream>
#include<string>
using namespace::std;

int main(void)
{
	string str1, str2;
	cout << "Enter two string:";
	cin >> str1 >> str2;

	if (str1 > str2)
		cout << "The max is " << str1 << endl;
	else if (str1 < str2)
		cout << "The max is " << str2 << endl;
	else
		cout << "They are the same!" << endl;

	if (str1.length() < str2.length())
		cout << str1 << " is longer" << endl;
	else if (str1.length() > str2.length())
		cout << str2 << " is longer" << endl;
	else
		cout << "They have the same length" << endl;

	return 0;
}
