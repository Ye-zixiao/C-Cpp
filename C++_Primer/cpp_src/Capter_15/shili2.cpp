#include<iostream>
#include"String.h"
using namespace::std;

class Base {
public:
	virtual String func(String str = "Base default String") const {
		return str;
	}
};

class Derived :public Base {
public:
	String func(String str="Derived default String") const override {
		return str;
	}
};

int main(void)
{
	Derived item;
	Base& ref = item;
	cout << ref.func() << endl;

	return 0;
}
