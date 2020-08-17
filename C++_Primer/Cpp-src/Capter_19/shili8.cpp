#include<iostream>
#include<string>
#include<typeinfo>
using namespace::std;

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
	void print_base(void) const {
		cout << "Base::print_base" << endl;
	}

};

class Derived :public Base {
	int dvalue = 0;
public:
	Derived() = default;
	Derived(int v):
		Base(),dvalue(v){}

	int get(void) const override {
		return dvalue;
	}
	void print_derived(void) const {
		cout << "Derived::print_derived" << endl;
	}
};

int main(void)
{
	try {
		Derived item(10);
		const Base& base_ref = item;
		base_ref.print_base();
		const Derived& derived_ref = dynamic_cast<const Derived&>(base_ref);
		derived_ref.print_derived();
	}
	catch (bad_cast& err) {
		cerr << err.what() << endl;
	}

	return 0;

}
