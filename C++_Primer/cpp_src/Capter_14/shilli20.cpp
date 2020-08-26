#include<iostream>
#include"String.h"
using namespace::std;

class pString {
public:
	pString() = default;
	pString(const char*pstr):
		p(new String(pstr)){}
	~pString() {
		if (p)delete p;
	}

	String& operator*() {
		return *p;
	}
	String* operator->() {
		return &this->operator*();
	}

private:
	String* p = nullptr;
};

int main(void)
{
	pString pstr("hello world");
	cout << pstr->size() << endl;
	*pstr += " hello china";
	cout << pstr->size() << endl;

	return 0;
}
