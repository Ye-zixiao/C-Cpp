#include<iostream>
#include<random>
#include<cmath>
#include<iomanip>
using namespace::std;

int main(void)
{
	string str("hello"), next("next col");
	int value = -15;
	cout << "str:" << setw(12) << str << ' ' << next << endl
		<< "val:" << setw(12) << value << ' ' << next << endl;

	cout << left;
	cout << "str:" << setw(12) << str << ' ' << next << endl
		<< "val:" << setw(12) << value << ' ' << next << endl;

	cout << internal;
	cout << "str:" << setw(12) << str << ' ' << next << endl
		<< "val:" << setw(12) << value << ' ' << next << endl;

	cout << setfill('_') << right;
	cout << "str:" << setw(12) << str << ' ' << next << endl
		<< "val:" << setw(12) << value << ' ' << next << endl;

	//cin >> noskipws;
	//char ch;
	//while (cin >> ch)
	//	cout << ch;

	cout << showbase << hexfloat << uppercase;
	cout << sqrt(2.0) << endl;

	return 0;
}
