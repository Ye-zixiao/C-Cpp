#include<iostream>
using namespace std;

template<typename T,T max=9>
class Test
{
public:
	void print(void)
	{
		cout << "hello world!" << endl;
		cout << max << endl;
	}
};

template<typename T,T max=0>				//�������е������õ�������ģ������Ḳ�ǻ����е�������ģ�����
class SecondTest :public Test<T,max>
{
public:
	void hello_print(void)
	{
		this->print();						//������ģ����������������ͻ����еķ��麯��������ֱ�ӵ��á�
		(*this).print();
	/*	using Test<T,max>::print;
		print();*/
		Test<T,max>::print();               /*��Ҫԭ��
                                            C++��ģ���е����ƻ�������β��ң���Ϊ���׶β��ң�two-phase lookup����
                                        ����һ�������������ƣ������κη�ʽ������ģ����������ƣ�����ģ���������н�����ʱ��ͻ���в��ҡ�
                                        ��C++��׼�й涨��14.6.2 3����һ�������޵����Ʋ��ҵ�ʱ�򽫲��ῼ�������͵Ļ��ࡣ
                                        ����*/
	}
};

int main(void)
{
	SecondTest<int,10> test;
	test.hello_print();

	return 0;
}
