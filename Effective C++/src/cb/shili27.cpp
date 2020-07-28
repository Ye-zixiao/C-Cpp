#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Base {
	T value;
protected:
	Base(const T&t):
		value(t){}

	T getvalue(void) const {
		return value;
	}

	void modify_value(const T&t) {
		value = t;
	}
};

template<>
class Base<const char*> {
	const char* pstr;
protected:
	Base(const char*const &t):
		pstr(t){}

	const char* getvalue(void) const {
		return pstr;
	}

	void modify_value(const char* const& t) {
#ifdef DEBUG
		cout << "Base<const char*>::modify_value" << endl;
#endif
		pstr = t;
	}
};

template<typename T>
class Derived :public Base<T> {
public:
	Derived(const T&t):Base<T>(t){}
	T get(void) const {
		return this->getvalue();
	}

	void modify(const char* const& t) {
		this->modify_value(t);
	}
};

int main(void)
{
	Derived<const char*> item("hello world");
	cout << item.get() << endl;
	item.modify("show me the code");
	cout << item.get() << endl;

	return 0;
}
