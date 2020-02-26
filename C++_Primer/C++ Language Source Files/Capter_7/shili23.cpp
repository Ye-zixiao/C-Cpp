#include<iostream>
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):value(val),dvalue(3){}//这个构造函数也起到了转换构造函数的作用
	Test(int val,double dval):value(val),dvalue(dval){}

	int get_value(void)const { return value; }
	double get_dvalue(void) const { return dvalue; }
	const Test& add(const Test& item) {
		value += item.value;
		dvalue += item.dvalue;
		return *this;
	}

private:
	int value;
	double dvalue;
};

int main(void)
{
	Test test_1(10, 3);
	cout << test_1.add(5).get_dvalue() << endl;
	cout << test_1.get_value() << endl;

	return 0;
}
