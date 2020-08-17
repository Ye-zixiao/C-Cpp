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
	double* test_cast = static_cast<double*>(p_1);//使用static_cast将void指针强制转换回原来的指针类型
	cout << (*test_cast)++ << endl;
	cout << *test_cast << endl;

	cout << "--------------------------------" << endl;
	const int value = 10;
	const int* pvalue = &value;
	int* ppvalue = const_cast<int*>(pvalue);
	cout << *pvalue << ' ' << *ppvalue << endl;
	*ppvalue = 11;//虽然使用const_cast可以将指向const的指针赋给另一个普通指针，但是最好不要使用该普通指针去改变所指向对象的值
	cout << *ppvalue << endl;

	return 0;
}
