#include<iostream>
#include<cstdlib>
using namespace::std;

class Test {
public:
	Test() = default;
	~Test() try{//合成的异常说明与编译器为类合成的析构函数所得的异常说明一致
		throw runtime_error("test");
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}
};

void func(void) {
	Test item;
	cout << boolalpha << noexcept(item.~Test()) << endl;
}


int main(void)
{
	try {
		func();
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}

	return 0;
}
