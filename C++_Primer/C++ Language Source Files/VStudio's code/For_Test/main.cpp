#include<iostream>
using namespace std;

class Base {
public:
	virtual void func(int value = 31) {
		cout << value << endl;
	}
};

class Derived :public Base {
public:
	//
};

int main(void)
{
	Derived item;
	item.func();
	item.func(24);
	return 0;
}