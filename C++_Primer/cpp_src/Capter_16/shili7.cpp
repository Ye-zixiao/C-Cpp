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

template<typename T,unsigned N>
T* Begin(T(&arr)[N]) {
	return arr;//arr好像是对数组名的引用，[N]中间的N只是表示这个数组名代表的数组中的元素有N个
}

template<typename T,unsigned N>
T* End(T(&arr)[N]) {
	return arr + N;
}

template<typename T>
int* BBegin(T& arr) {
	return arr;
}


int main(void)
{
	int arr[10];
	iota(Begin(arr), End(arr), 1);
	/*cout << Begin(arr) << endl;
	cout << End(arr) << endl;
	cout << BBegin(arr) << endl;*/
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
