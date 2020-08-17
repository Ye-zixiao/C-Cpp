#include<iostream>
using namespace::std;

class X {
public:
	void get(void) const { cout << "X's get()" << endl; }
};

class Y {
	X x;
public:
	void get(void) const { cout << "Y's get()" << endl; }
	X& operator*() { return x; }
	X* operator->() { return &this->operator*(); }
};

class Z {
	Y y;
public:
	Y& operator*() { return y; }
	Y operator->() { return this->operator*(); }
};

int main(void)
{
	Z z;
	z->get();
}
