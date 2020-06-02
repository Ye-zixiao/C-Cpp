#include<iostream>
#include<string>
#include<tuple>
using namespace::std;

struct Base {
	Base(int val):value(val){}
	virtual ~Base(){}

	virtual int getval(void) const {
		return value;
	}

private:
	int value;
};

struct Derived :Base {
	Derived(int v1,int v2):
		Base(v1),derived_value(v2){}

	int getval(void) const override {
		return derived_value;
	}

private:
	int derived_value;
};

int main(void)
{
	Derived item(1, 2);
	Base* pbase = &item;
	try {
		throw* pbase;/*抛出的虽然是一个指向Derived派生类对象的指针，但是由于该指针的
					 静态类型是指向基类的指针，所以我们只能抛出派生类对象中的基类子对象*/
	}
	catch (const Base& item) {
		cout << item.getval() << endl;
	}

	return 0;
}
