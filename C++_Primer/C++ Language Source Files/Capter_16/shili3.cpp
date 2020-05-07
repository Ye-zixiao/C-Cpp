#include<string>
#include<iostream>
#include<numeric>
using namespace::std;

template<typename T,unsigned sz>
inline void print(const T(&arr)[sz]) {
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}

template<typename T>
inline T* Begin(T* parr) {
	return parr;
}

template<typename T,unsigned sz>
inline T* End(T(&arr_ref)[sz]) {
	return &arr_ref[0] + sz;
}

int main(void)
{
	int arr[10];
	iota(Begin(arr), End(arr), 101);
	print(arr);

	string sarr[] = { "hello","world","show","me","the","world" };
	print(sarr);

	return 0;
}
