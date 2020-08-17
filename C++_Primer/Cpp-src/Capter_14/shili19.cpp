#include<iostream>
using namespace::std;

class SmallInt {
	friend SmallInt operator+(const SmallInt& lhs, const SmallInt& rhs);
	//friend SmallInt operator+(const SmallInt& lhs, double rhs);
public:
	SmallInt(int v){}

	operator int() const {
		return 1;
	}
};

SmallInt operator+(const SmallInt& lhs, const SmallInt& rhs) {
	return SmallInt(1);
}

class LongDouble {
	friend LongDouble operator+(const LongDouble& lhs, const LongDouble& rhs);
public:
	LongDouble(double i){}

	operator double()const {
		return 1.1;
	}
	operator float()const {
		return 2.2;
	}

	LongDouble operator+(const SmallInt& lhs) {
		return LongDouble(1.1);
	}
};

LongDouble operator+(const LongDouble& lhs, const LongDouble& rhs) {
	return LongDouble(1.1);
}

int main(void)
{
	SmallInt si(1);
	LongDouble ld(0.1);
	ld = si + ld;
	ld = ld + si;

	SmallInt s1(1);
	double d = s1 + 3.14;
	double d_modified = s1 + 3;//3到SmallInt的转换也是使用了类类型转换，转换等级不比3.14更优
}
