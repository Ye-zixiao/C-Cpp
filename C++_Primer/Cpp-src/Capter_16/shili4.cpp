#include<iostream>
#include<string>
using namespace::std;

template<typename T,unsigned sz>
inline constexpr unsigned arr_size(const T(&arr)[sz]) {
	return sz;
}

int main(void)
{
	int arr[100];
	cout << arr_size(arr) << endl;

	string sarr[199];
	cout << arr_size(sarr) << endl;

	int arr_2[arr_size(sarr)];

	return 0;
}
