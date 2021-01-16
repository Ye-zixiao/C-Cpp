#include<iostream>
#include<string>
using namespace::std;

class Base {
public:
	Base() = default;
	Base(const string&str):
		pstr(new string(str)){}
	Base(const Base&item):
		pstr(new string(*item.pstr)){
		cout << "Base(const Base&)" << endl;
	}
	Base(Base&& item)noexcept :
		pstr(std::move(item.pstr)) {
		cout << "Base(Base&&)noexcept" << endl;
		item.pstr = nullptr;
	}
	virtual ~Base() {
		cout << "~Base()" << endl;
		if (pstr)delete pstr;
	}

	Base& operator=(const Base& item) {
		if (this != &item) {
			if (pstr)delete pstr;
			pstr = new string(*item.pstr);
		}
		return *this;
	}
	Base& operator=(Base&& item)noexcept {
		if (this != &item) {
			if (pstr)delete pstr;
			pstr = std::move(item.pstr);
			item.pstr = nullptr;
		}
		return *this;
	}

public:
	string getstr(void) const {
		return pstr ? *pstr : string();
	}

private:
	string* pstr = nullptr;
};

class Derived :public Base {
public:
	using Base::Base;
	//Derived(const string&str):
	//	Base(str){}

	/*
    默认构造函数、拷贝构造函数、移动构造函数、拷贝赋值运算符、移动赋值运算符、析构函数是被合成的而不是被继承的；
    除此之外的
	*/

	int getval(void) const {
		return value;
	}

private:
	int value = 0;
};

int main(void)
{
	Derived item("hello world");
	cout << item.getstr() << ' ' << item.getval() << endl;

	Derived item_cpy = item;
	cout << item_cpy.getstr() << ' ' << item_cpy.getval() << endl;

	Derived item_move(std::move(item));
	cout << item_move.getstr() << ' ' << item_move.getval() << endl;
	cout << item.getstr() << ' ' << item.getval() << endl;

	return 0;
}
