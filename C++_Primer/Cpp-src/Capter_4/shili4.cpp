#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	int arr[10];
	cout << sizeof(arr)/sizeof(int) << endl;

	cout << sizeof(int) << ' ' << sizeof(char) << ' ' << sizeof(short) << ' ' << sizeof(long) << endl;
	cout << sizeof(long long) << ' ' << sizeof(float) << ' ' << sizeof(double) << ' ' << sizeof(size_t) << endl;
	cout << sizeof(long double) << endl;

	//int* p = nullptr;
	//cout << sizeof(p) << endl;
	int x[10], * p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;//��32λ��ϵ�У�ָ��ռ��4���ֽڣ�����64λ��ϵ�У�ָ��ռ��8���ֽڣ�
	//����pָ������������Ԫ�أ���������int�����ڲ�ͬ������ռ�õĿռ��С�ǲ�ͬ�ģ������������Ľ���ڲ�ͬ�Ļ����Ͽ��ܲ��ܴ�

	return 0;
}
