#include<iostream>
#include<vector>
using namespace::std;

class NoDefault {
public:
	NoDefault(int){}//û��Ĭ�Ϲ��캯��

};

class C {
public:
	C(int value=0):my_mem(value){}//������Ĭ�Ϲ��캯��������

private:
	NoDefault my_mem;
};

int main(void)
{
	C test;
	vector<C> test_C;//������C(int value=0)���Ĭ�Ϲ��캯��
	//vector<NoDefault> test_nd(10);
	//����NoDefault��û��Ĭ�ϵĹ��캯����ʹ��vector�޷�������Ĭ�Ϲ��캯������ֵ��ʼ��

	return 0;
}
