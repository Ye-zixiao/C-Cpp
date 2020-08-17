#include<iostream>
#include<string>
#include<utility>
using namespace::std;

struct Base {
	Base() = default;
	Base(const string&s):str(s){}

	Base(const Base& item) :
		str(item.str) {
		cout << "Base(const Base&)" << ++i << endl;
	}
	/*Base(Base&&) = delete;*/
	virtual ~Base() = default;

	string str;
	static int i;
};

int Base::i = 0;

struct Derived :Base {
	Derived() = default;
	Derived(const string& s) :
		mem(s){}

	Derived(const Derived&) = delete;
	/*Derived(Derived&& item) noexcept:
		mem(item.mem) {
		cout << "Derived(Derived&&)" << endl;
	}*/
	Derived(Derived&&)= default;//默认的derived的移动构造函数与自定义的derived的移动构造函数是不同的

	Derived& operator=(const Derived&) = delete;
	Derived& operator=(Derived&&) = delete;

	Base mem;
};

Derived f(void) {
	return Derived("show");
}

int main(void)
{
	Derived item("hello world");
	Derived item_move = std::move(item);
	Derived item_f = f();

	cout << item.mem.str << endl;
	cout << item_move.mem.str << endl;
	cout << item_f.mem.str << endl;

	return 0;
}
