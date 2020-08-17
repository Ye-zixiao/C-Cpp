#include<iostream>
#include<string>
using namespace::std;

int main(void)
{
	union {
		char cvar;
		int ivar;
		double dvar;
	};

	dvar = 2.3;
	cout << dvar << ' ' << ivar << endl;
	ivar = 3;
	cout << dvar << ' ' << ivar << endl;
	cvar = 'c';
	cout << cvar << ' ' << ivar << ' ' << dvar << endl;

	return 0;
}
