#include<iostream>
#include<string>

namespace nsp {
	int value;
	void f(void) {
		std::cout << "hello world" << std::endl;
	}
}

int value = 101;

void func(void) {
	using namespace::nsp;
	f();
	//value = 10;
	::value = 10222;
	nsp::value = 131;
}

//f();

int main(void)
{
	func();
	//value = 10;
	return 0;
	//value = 10;
}
