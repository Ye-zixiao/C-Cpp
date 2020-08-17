#include<iostream>
#include<memory>
#include<string>
using namespace::std;

int main(void)
{
	int* pv = new int(32);
	{
		unique_ptr<int> pvalue(pv);
		*pv = 100;
		cout << *pvalue << endl;
	}
	cout << *pv << endl;//虽然独一指针销毁了所指向的动态对象，但是原来的内置指针仍然指向该内存块
	//在g++编译器中运行后甚至独一指针在销毁时都没有释放所指向的内存，或者说是原来的值仍然还在
	*pv = 102;
	cout << *pv << endl;

	return 0;
}
