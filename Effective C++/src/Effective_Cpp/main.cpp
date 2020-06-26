#include<iostream>
using namespace std;

class Rational {
	friend const Rational operator*(const Rational&, const Rational&);
	friend ostream& operator<<(ostream&, const Rational&);
public:
	Rational(int num=0,int den=1):
		n(num),d(den){}

private:
	int n, d;
};

ostream& operator<<(ostream& os, const Rational& r) {
	if (r.d == 0)return os << 0;
	else return os << r.n << '/' << r.d;
}

const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

int main(void)
{
	Rational lhs(3, 5), rhs(1, 2);
	cout << lhs * rhs << endl;


	return 0;
}