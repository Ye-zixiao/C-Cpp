#include<iostream>
#include<string>
using namespace::std;

class Test {
	string str;
	int value = 0;
public:
	Test() = default;
	Test(const string&s,int v):
		str(s),value(v){}

	const string& getstr(void) const {
		return str;
	}
	const int& getval(void) const {
		return value;
	}
	static const string Test::* ret_pstr(void) {
		return &Test::str;
	}

};

int main(void)
{
	Test test("hello world", 32);
	const string Test::* pTest_str = Test::ret_pstr();
	cout << test.*pTest_str << endl;

	Test* ptest = &test;
	cout << ptest->*pTest_str << endl;
	return 0;
}
