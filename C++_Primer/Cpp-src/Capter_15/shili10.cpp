#include<iostream>
#include<string>
#include<utility>
using namespace::std;

class Base {//基类Base是不可移动的
public:
	Base() = default;

	Base(const Base& item) {
		cout << "Base(const &)" << endl;
	}
	//Base(Base&& item) noexcept{
	//	cout << "Base(Base&&)noexcept" << endl;
	//}

	virtual ~Base() {
		cout << "~Base()" << endl;
	}

};

class Derived :public Base {
public:
	Derived() = default;

	Derived(Derived&&) = default;
	//编译器不会为这个类合成移动操作，但意外的是，它不会被删除！！虽然移动构造函数不可合成，但是拷贝构造函数是可以合成的

	~Derived() {
		cout << "~Derived()" << endl;
	}
};

class withBase {
public:
	withBase() = default;
	withBase(withBase&&) = default;
	~withBase() {}

private:
	Base base;
};

int main(void)
{
	Derived item;
	Derived item_mv = std::move(item);

	cout << "-----------------------------------" << endl;
	withBase test;
	withBase test_mv = std::move(test);

	return 0;
}
