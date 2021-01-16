#include<iostream>
#include<typeinfo>
using namespace::std;

struct Base {
	virtual ~Base() {}
};

struct Derived :Base {
	//
};

int main(void)
{
	Base* pbase = new Derived();
	if (Derived* pderived = dynamic_cast<Derived*>(pbase))
		if (typeid(*pderived) == typeid(Derived))
			cout << "match1" << endl;
	try {
		Derived& derived_ref = dynamic_cast<Derived&>(*pbase);
		if (typeid(derived_ref) == typeid(Derived))
			cout << "match2" << endl;
		if (Derived* pderived = dynamic_cast<Derived*>(pbase))
			if (typeid(*pderived) == typeid(derived_ref))
				cout << "match3" << endl;
	}
	catch (bad_cast& err) {
		cerr << err.what() << endl;
	}
	delete pbase;

	return 0;
}
