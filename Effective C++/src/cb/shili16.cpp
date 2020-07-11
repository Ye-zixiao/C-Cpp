#include<iostream>
using namespace std;

class Base {
public:
	virtual int get(int value) const {
		return value + 10;
	}
};

class Derived :private Base {
public:
	Derived(int v) :myvalue(v) {}

	int myget(void)const {
		return get(myvalue);
	}

private:
	int myvalue;

	//keyword 'final' makes Derived Class's Derived Class' function get() can't override
	int get(int value) const override final{
		return value + 11;
	}
};

class Derived_D :public Derived {
public:
	using Derived::Derived;
private:
	/*int get(int value) const override {
		return value + 12;
	}*/
};

int main(void)
{
	Derived item(10);
	Derived_D itemD(10);
	cout << item.myget() << endl;
	cout << itemD.myget() << endl;

	return 0;
}
