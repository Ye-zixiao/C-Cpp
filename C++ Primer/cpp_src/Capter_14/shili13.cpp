#include<iostream>
#include<string>
using namespace::std;

class IntVal {
public:
	IntVal(int val):value(val){}

    operator double() const {
		cout << "operator double() const" << endl;
		return value;
	}
	operator const double() {
		cout << "operator const double()" << endl;
		return value;
	}


private:
	int value;
};

int main(void)
{
	IntVal int_value(12);
	double dvalue = int_value;
	dvalue += 0.1;
	cout << dvalue << endl;

	return 0;
}
