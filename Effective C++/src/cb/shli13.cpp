#include<iostream>
using namespace std;

class Base {
public:
	Base() = default;

	virtual void add(void) {
		++value;
	}
	int get(void)const { return value; }

protected:
	int value = 0;
};

class Derived :public Base {
public:
	Derived() = default;
	void add(void) override {
		//static_cast<Base&>(*this).add();//wrong
		//Base::add();//right
		static_cast<Base>(*this).add();//wrong
		++value;
	}
};

int main(void)
{
	Derived item;
	item.add();
	cout << item.get() << endl;

	return 0;
}
