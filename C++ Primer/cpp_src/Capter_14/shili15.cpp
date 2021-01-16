#include<iostream>
using namespace::std;

struct A {
	A() = default;
	A(int v){
		cout << "A(int)" << endl;
	}
	A(double v){
		cout << "A(double)" << endl;
	}

	operator int() const {
		cout << "operator int() const" << endl;
		return 1;
	}
	operator double()const {
		cout << "operator double() const" << endl;
		return 1.2;
	}
};

void f(A v){}
void f2(long double v){}

int main(void)
{
	long double a = 0;
	//f(a);//��ΪA�������ֱ����double��int��ת�����캯����������һ��long double��ʱ���뽫��ת����A���;ͻ����������ת��
	f(static_cast<int>(a));//����ʹ����ʽǿ��ת���ﵽĿ��
	f(static_cast<double>(a));

	A b;
	//f2(b);//��ΪA�����������ֱ����ת����double��int������ת�������������ϣ������ת����long double��ʱ�����ɶ�����ת��
	f2(b.operator double());
	f2(b.operator int());

	return 0;
}
