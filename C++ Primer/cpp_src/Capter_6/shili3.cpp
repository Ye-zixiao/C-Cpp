#include<iostream>
#include<vector>
#include<string>
//#include"header.h"
using namespace::std;

void test(int value)
{
	value = 10;
	cout << value << endl;
}

//void test(const int value)
//{
//	cout << value << endl;
//}

void test(int* pvalue)
{
	*pvalue = 99;
	cout << *pvalue << endl;
}

void test(const int* pvalue)
{
	cout << *pvalue << endl;
}

int main(void)
{
	int value(23);
	const int* pvalue = &value;
	test(static_cast<const int>(value));//���10
	//����ʵ����һ��const int���͵Ĳ���������ʵ�γ�ʼ���β�ʱ��ȥ������const���Ӷ������β�Ϊint���͵�testͬ������

	test(pvalue);//���23
	//����pvalue��һ�����еײ�const��ָ�룬���Ի���þ��еײ�const���βε�testͬ������

	test(&value);//���99
	//����&value��һ����ֵ����һ������const������������û�еײ�const�����Ի����û�еײ�const���βε�testͬ������

	return 0;
}
