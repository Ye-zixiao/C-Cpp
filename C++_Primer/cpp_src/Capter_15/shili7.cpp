#include<iostream>
#include"String.h"
#include<utility>
using namespace::std;

class Base {
public:
	Base() = default;
	Base(const String&s):str(s){
		cout << "Base(const String&)" << endl;
	}
	Base(const Base&item):str(item.str){}
	Base(Base&& item) noexcept:str(std::move(item.str)){}
	~Base() {
		cout << "~Base()" << endl;
	}

	Base& operator=(const Base& item) {
		str = item.str;
		return *this;
	}
	Base& operator=(Base&& item)noexcept {
		str = std::move(item.str);
		return *this;
	}

	String getstr(void) const {
		return str;
	}

private:
	String str;
};

class Derived :public Base {
public:
	Derived():Base(){}
	Derived(const String&s,int v):
		Base(s),value(v){
		cout << "Derived(const String&,int)" << endl;
	}
	Derived(const Derived&item):
		Base(item),value(item.value){}
	Derived(Derived&&item)noexcept:
		Base(std::move(item)),value(std::move(value)){}
	~Derived() {
		cout << "~Derived()" << endl;
	}

	Derived& operator=(const Derived& item) {
		Base::operator=(item);
		value = item.value;
		return *this;
	}
	Derived& operator=(Derived&& item) noexcept {
		Base::operator=(std::move(item));
		value = std::move(item.value);
		return *this;
	}

	int getval(void) const {
		return value;
	}

private:
	int value = 0;
};

int main(void)
{
	cout << sizeof(Derived) << endl;
	Derived item("hello world", 23);
	cout << item.getstr() << endl;
	cout << item.getval() << endl;

	return 0;
}
