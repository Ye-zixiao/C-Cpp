#include<iostream>
using namespace std;

template<typename T> class Rational;

template<typename T>
Rational<T> doMultiply(const Rational<T>&, const Rational<T>&);

template<typename T>
class Rational {
	friend Rational operator*(const Rational& lhs, const Rational& rhs) {
		return doMultiply(lhs, rhs);
	}
public:
	Rational(T n=0,T d=1):
		numerator(n),denominator(d){}

	T ret_numerator(void) const {
		return numerator;
	}
	T ret_denominator(void) const {
		return denominator;
	}

private:
	T numerator, denominator;
};

template<typename T>
Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs) {
	return Rational<T>(lhs.ret_numerator() * rhs.ret_numerator(),
		lhs.ret_denominator() * rhs.ret_denominator());
}

int main(void)
{
	Rational<int> item(35, 232);
	/*因为实例化Rational的时候也使得实例化类中的友元函数被声明和定义，
	这使得编译器直到这样一个函数的存在，且这样的函数不是函数模板，也就
	根本不存在模板类型实参推断的过程*/
	Rational<int> result = item * 2;
	cout << result.ret_numerator() << '/' << result.ret_denominator() << endl;
	return 0;
}
