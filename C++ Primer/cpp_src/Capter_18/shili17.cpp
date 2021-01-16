#include<iostream>
#include<string>
using namespace::std;

class Base {
	int value;
public:
	Base(int v):value(v){}

	int getval(void) const {
		return value;
	}
};

class Derived :public Base {
protected:
	string str;
public:
	Derived(int v,const string&s):
		Base(v),str(s){}

	string getstr(void) const {
		return str;
	}
};

class MultiInheritance :public Derived, public Base {
public:
	MultiInheritance(int v1,const string&s,int v2):
		Derived(v1,s),Base(v2){}


};

int main(void)
{
	MultiInheritance item(1, "hello", 2);
	cout << item.getstr() << endl;
	cout << item.Derived::getval() << ' ' << item.Base::getval() << endl;
	//cout << item.getval() << endl;

	return 0;
}
