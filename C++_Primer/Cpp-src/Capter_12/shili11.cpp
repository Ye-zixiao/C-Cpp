#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cstring>
using namespace::std;

int main(void)
{
	/*const char* cp1 = "hello wrold", * cp2 = " show me the world";
	size_t len = strlen(cp1) + strlen(cp2) + 1;
	char* cp = new char[len]();
	strcat_s(cp, len, cp1);
	strcat_s(cp, len, cp2);
	cout << cp << endl;
	delete[]cp;*/

	string str1 = "hello world", str2 = " show me the world";
	size_t len = str1.size() + str2.size() + 1;
	char* cp = new char[len]();
	strcpy(cp,  (str1 + str2).c_str());
	//ÔÚvsÖÐÎªtrcpy_s(cp,len,(str1+str2).c_str());
	cout << cp << endl;
	delete[]cp;

	return 0;
}
d
