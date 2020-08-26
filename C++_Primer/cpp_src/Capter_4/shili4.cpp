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
	cout << sizeof(p) / sizeof(*p) << endl;//在32位体系中，指针占用4个字节，而在64位体系中，指针占用8个字节，
	//由于p指向的是数组的首元素，但是由于int类型在不同机器上占用的空间大小是不同的，所以这个输出的结果在不同的机器上可能差距很大

	return 0;
}
