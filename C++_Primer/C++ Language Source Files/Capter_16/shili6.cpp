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
	print(arr);//��ʱT���������ͣ�

	print_(arr);//�������ģ�����ɵ�ʵ���е�T��int
	print__(arr);
}
