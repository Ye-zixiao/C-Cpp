#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	int i = 100, j = 31;
	cout << static_cast<double>(i / j) << endl;
	cout << static_cast<double>(i) / j << endl;
	cout << i / static_cast<double>(j) << endl;

	double test_num = 3.3, * p_test = &test_num;
	void* p_1 = p_test;
	double* test_cast = static_cast<double*>(p_1);//ʹ��static_cast��voidָ��ǿ��ת����ԭ����ָ������
	cout << (*test_cast)++ << endl;
	cout << *test_cast << endl;

	cout << "--------------------------------" << endl;
	const int value = 10;
	const int* pvalue = &value;
	int* ppvalue = const_cast<int*>(pvalue);
	cout << *pvalue << ' ' << *ppvalue << endl;
	*ppvalue = 11;//��Ȼʹ��const_cast���Խ�ָ��const��ָ�븳����һ����ָͨ�룬������ò�Ҫʹ�ø���ָͨ��ȥ�ı���ָ������ֵ
	cout << *ppvalue << endl;

	return 0;
}
