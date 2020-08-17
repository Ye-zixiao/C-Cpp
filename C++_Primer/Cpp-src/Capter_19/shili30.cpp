#include<iostream>
#include<string>
using namespace::std;

union my_type {
	int ivalue;
	double dvalue;
	char ch;
};

static union {
	int yellow;
	double fuck;
};

int main(void) {
	my_type item = { 23 };
	cout << item.ivalue << endl;
	try {
		cout << item.dvalue << endl;
	}
	catch (exception& err) {
		cerr << err.what() << endl;
	}

	union {
		int red;
		double green;
	};

	red = 42;
	green = 3.2;
	//cout << red << endl;
	cout << green << endl;
	fuck = 32.123;
	cout << fuck << endl;
	yellow = 3;
	cout << yellow << endl;

	return 0;
}
