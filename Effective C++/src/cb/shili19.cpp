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
	/*��Ϊʵ����Rational��ʱ��Ҳʹ��ʵ�������е���Ԫ�����������Ͷ��壬
	��ʹ�ñ�����ֱ������һ�������Ĵ��ڣ��������ĺ������Ǻ���ģ�壬Ҳ��
	����������ģ������ʵ���ƶϵĹ���*/
	Rational<int> result = item * 2;
	cout << result.ret_numerator() << '/' << result.ret_denominator() << endl;
	return 0;
}
