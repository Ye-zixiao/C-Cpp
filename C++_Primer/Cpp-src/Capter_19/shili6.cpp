#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include<string>
using namespace::std;

//void* operator new(size_t sz) {
//	if (void* mem = malloc(sz))
//		return mem;
//	else
//		throw bad_alloc();
//}
//
//void operator delete(void* mem) {
//	free(mem);
//}

int main(void)
{
	int* pvalue = new int;//������һ��int��С���ڴ�ռ�
	new (pvalue) int(342);
	cout << *pvalue << endl;
	string* pstr = new string;//������һ��string��С���ڴ�ռ䣬ͬʱʹ��Ĭ�ϳ�ʼ��������һ����string����
	//pstr->~basic_string();
	new (pstr) string(10, 'c');
	cout << *pstr << endl;

	string str;
	new (&str) string("hello world");
	cout << str << endl;

	int* pp = static_cast<int*>(operator new(sizeof(int)));
	cout << *pp << endl;
	new (pp) int(523);
	cout << *pp << endl;
	delete pp, nothrow;


	delete pvalue;
	delete pstr;
	return 0;
}
