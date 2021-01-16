#include<iostream>
using namespace::std;

class Base {
public:
	void func(void) {
		cout << "void Base::func(void)" << endl;
	}
	void func(int v) {
		cout << "void Base::(int v)" << endl;
	}
	void func(double d) {
		cout << "void Base::(double d)" << endl;
	}
};

class Derived :public Base {
public:
	using Base::func;
	void func(void) {
		cout << "void Derived::func(void)" << endl;
	}
};

int main(void)
{
	Derived item;
	item.func();
	item.func(1);
	item.func(1.2);

	return 0;
}
