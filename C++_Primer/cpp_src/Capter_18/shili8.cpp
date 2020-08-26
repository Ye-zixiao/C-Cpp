#include<iostream>
#include<string>
//#include <functional>
using namespace::std;

namespace {
	int value = 10;
}

namespace nsp {
	namespace {
		int static_value = 32;
	}
}

void func(void) {
	value = 100;
	nsp::static_value = 42424;
}

int main(void)
{
	cout << value << endl;
	func();
	cout << value << endl;
	cout << nsp::static_value << endl;

	return 0;
}
