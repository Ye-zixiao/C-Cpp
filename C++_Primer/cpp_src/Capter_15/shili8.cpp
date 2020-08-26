#include<iostream>
using namespace::std;

class Base {
public:
	virtual ~Base() {
		cout << "~Base()" << endl;
	}
};

class nov_Base {
public:
	~nov_Base() {
		cout << "~nov_Base()" << endl;
	}
};

class Derived :public Base {
public:
	~Derived() {
		cout << "~Derived()" << endl;
	}
};

class nov_Derived :public nov_Base {
public:
	~nov_Derived() {
		cout << "nov_Derived()" << endl;
	}
};

int main(void)
{
	Base* pbase = new Derived();
	delete pbase;
	//由于Derived的基类的析构函数是虚析构函数，所以指向base的指针会依据所指向的对象的动态类型调用对应版本的析构函数
	//且派生类的析构函数执行完自己的析构函数后，会自动地调用基类的析构函数会释放派生类中的基类对象

	nov_Base* pnovbase = new nov_Derived();
	delete pnovbase;
	//由于nov_Derived的基类的析构函数不是虚析构函数，所以delete这个指针的时候只能根据指针的静态类型调用基类版本的析构函数，而不是派生类的析构函数

	return 0;
}
