#include<iostream>
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):value(val){}

	static int get_csvalue(void) { return csvalue; }
	int get_value(void) { return value; }
	//void set(int val) { csvalue = val; }

	const int& get_csvalueref(void) {
		return csvalue;
	}

private:
	int value;
	static const int csvalue = 10;
};

void func(const int& r)
{
	//
}

//const int Test::csvalue;

int main(void)
{
	Test test(11);
	cout << test.get_csvalue() << endl;
	func(test.get_csvalueref());

	return 0;
}
