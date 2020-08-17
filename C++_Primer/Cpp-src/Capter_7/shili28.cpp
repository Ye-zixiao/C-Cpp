#include<iostream>
#include<string>
using namespace::std;

class Debug {
public:
	constexpr Debug(bool b = true):hw(b),io(b),other(b){}
	constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}

	constexpr bool any() const { return hw || io || other; }
	/*void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }*/

private:
	bool hw;
	bool io;
	bool other;
};

class Test {
public:
	constexpr Test(int value=0):constexpr_value(value){}

	constexpr int get_value(void) const { return constexpr_value; }
	//constexpr int get_value(void) { return constexpr_value; }

private:
	int constexpr_value;
};

int main(void)
{
	constexpr Test test(10);
	//Test test(10);
	cout << test.get_value() << endl;

	int arr[test.get_value()];

	constexpr Debug testfor(false);
	if(testfor.any())

	return 0;
}
