#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	try {
		string fmt = "$2.$5.$7";
		string phonenum;
		regex re("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
		while (getline(cin, phonenum)) {
			cout << regex_replace(phonenum, re, fmt) << endl;
		}
	}
	catch (regex_error& err) {
		cout << err.what() << ' ' << err.code() << endl;
	}
	return 0;
}
