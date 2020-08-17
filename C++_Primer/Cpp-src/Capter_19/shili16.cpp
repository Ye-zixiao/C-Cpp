#include<iostream>
#include<string>
//#include"Sales_data.h"
#include<typeinfo>
using namespace::std;

struct Sales_data{};

class Base {
	int bvalue = 0;
public:
	Base() = default;
	Base(int v):
		bvalue(v){}
	virtual ~Base(){}

	virtual int get(void) const {
		return bvalue;
	}
	virtual bool equal(const Base& rhs)const {
		return bvalue == rhs.bvalue;
	}

};

class Derived :public Base {
	int dvalue = 0;
public:
	Derived() = default;
	Derived(int bv,int dv):
		Base(bv),dvalue(dv){}

	int get(void) const override{
		return dvalue;
	}
	bool equal(const Base& rhs)const override{
		auto rhs_cref = dynamic_cast<const Derived&>(rhs);
		return	Base::equal(rhs) && dvalue == rhs_cref.dvalue;
	}
};

bool operator==(const Base& lhs, const Base& rhs) {
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main(void)
{
	Base bitem_1(12), bitem_2(24);
	Derived ditem_1(12, 23), ditem_2(12, 23);
	if (bitem_1 == ditem_1)
		cout << "bitem_1==ditem_1" << endl;
	else
		cout << "bitem_1!=ditem_1" << endl;
	if (ditem_1 == ditem_2)
		cout << "ditem_1==ditem_2" << endl;
	else
		cout << "ditem_1!=ditem_2" << endl;

	int arr[10];
	Derived d;
	Base* pb = &d;
	cout << typeid(42).name() << endl
		<< typeid(arr).name() << endl
		<< typeid(Sales_data).name() << endl
		<< typeid(string).name() << endl
		<< typeid(pb).name() << endl
		<< typeid(*pb).name() << endl;

	return 0;
}
