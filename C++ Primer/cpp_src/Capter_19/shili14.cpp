#include<iostream>
#include<typeinfo>
using namespace::std;

struct Base {
	virtual ~Base(){}
	void func(void) const{}
};

struct Derived :Base {};

int main(void)
{
	Base* pbase = new Derived();
	Derived* pderived = dynamic_cast<Derived*>(pbase);
	cout << typeid(*pbase).name() << endl;
	cout << typeid(*pderived).name() << endl;

	return 0;
}
