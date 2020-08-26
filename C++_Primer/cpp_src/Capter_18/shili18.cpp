#include<iostream>
#include<string>
using namespace::std;

struct Base {
	void print(void) {
		cout << "Base::print()" << endl;
	}
};

struct D1 :public virtual Base {
	void print(void) {
		cout << "D1::print()" << endl;
	}
};

struct D2 :public virtual Base {
	void print(void) {
		cout << "D2::print()" << endl;
	}
};

struct Derived :D1, D2 {
	//
};

int main(void)
{
	Derived item;
	//item.print();
	//item.D2::print();
	item.Base::print();

	return 0;
}
