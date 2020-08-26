#include<iostream>
using namespace::std;

class Base {
public:
	virtual void print(void) const {
		cout << "void Base::print(void) const" << endl;
	}
};

class Derived :public Base {
public:
	void print(void) const override {
		this->Base::print();
		cout << "void Derived::print(void) const override" << endl;
	}
};

int main(void)
{
	Derived item;
	item.print();

	return 0;
}
