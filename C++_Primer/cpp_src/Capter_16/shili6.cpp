#include<iostream>
#include<numeric>
using namespace::std;


template<typename T>
void print(const T& arr) {
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}

template<typename T,unsigned sz>
void print_(const T(&arr)[sz]) {
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}

using Array = int[10];
void print__(const Array& arr) {
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}

int main(void)
{
	int arr[10];
	iota(begin(arr), end(arr), 1);
	print(arr);//此时T是数组类型！

	print_(arr);//这个函数模板生成的实例中的T是int
	print__(arr);
}
