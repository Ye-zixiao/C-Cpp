#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

//int main(void)
//{
//	string str = "hello world";
//	//for (auto& c : str)
//	for(char &c:str)
//		c = 'X';
//	cout << str << endl;
//	return 0;
//}

//int main(void)
//{
//	string str = "hello world!";
//	decltype(str.size()) cnt = 0;
//	while (cnt < str.size())
//	{
//		str[cnt++] = 'X';
//	}
//	cout << str << endl;
//
//	return 0;
//}

int main(void)
{
	string str = "hello world!";
	for (decltype(str.size()) cnt = 0; cnt < str.size(); ++cnt)
		str[cnt] = 'X';
	cout << str << endl;

	return 0;
}
