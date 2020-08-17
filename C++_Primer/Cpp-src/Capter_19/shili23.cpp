#include<iostream>
#include<string>
using namespace::std;

class Test {
	int lvalue = 0, rvalue = 0;
	string str;
public:
	Test() = default;
	Test(const string& s, int l = 0, int r = 0) :
		str(s), lvalue(l), rvalue(r) {}

	int getrval(void) const {
		return rvalue;
	}
	int getlval(void) const {
		return lvalue;
	}
	const string& getstr(void) const {
		return str;
	}
};

int main(void)
{
	using get_val = int (Test::*)(void) const;
	using get_str = const string& (Test::*)(void) const;

	Test test("hello world", 2, 3), * ptest = &test;
	get_val lval = &Test::getlval, rval = &Test::getrval;
	cout << (test.*lval)() << ' ' << (test.*rval)() << endl;
	get_str str = &Test::getstr;
	cout << (ptest->*str)() << endl;

	const string& (Test:: * p_strf)(void) const = &Test::getstr;
	cout << (ptest->*p_strf)() << endl;

	return 0;
}
