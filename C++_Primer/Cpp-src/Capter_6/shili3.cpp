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
	test(static_cast<const int>(value));//输出10
	//由于实参是一个const int类型的参数，所以实参初始化形参时会去掉顶层const，从而调用形参为int类型的test同名函数

	test(pvalue);//输出23
	//由于pvalue是一个具有底层const的指针，所以会调用具有底层const的形参的test同名函数

	test(&value);//输出99
	//由于&value是一个右值，是一个顶层const，但是它并不没有底层const，所以会调用没有底层const的形参的test同名函数

	return 0;
}
