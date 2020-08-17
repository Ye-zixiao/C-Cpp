#include<iostream>
//#include<>
using namespace::std;

class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int value):i(value){
		if (value < 0 || value>225)
			throw out_of_range("Out of range");
	}

	operator int() const {
		return i;
	}

private:
	size_t i;
};

SmallInt operator+(const SmallInt& lhs, const SmallInt& rhs) {
	return lhs.i + rhs.i;
}


int main(void)
{
	SmallInt i = 21;
	auto sum = operator+(i, 21);
	cout << sum << endl;

	return 0;
}
