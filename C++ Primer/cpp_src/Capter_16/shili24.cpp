#include<iostream>
#include<string>
using namespace::std;

template<typename T>
void print(const T& arr) {
	for (const auto& elem : arr)
		cout << elem << ' '; cout << endl;
}

template<typename T,typename... Args>
void print(const T& arr, const Args&...arrs) {
	for (const auto& elem : arr)
		cout << elem << ' '; cout << endl;
	print(arrs...);
}

int main(void)
{
	int iarr[] = { 1,2,3,34,4,5,5,6,6,3 };
	string strarr[] = { "string1","string2","string3","string4" };
	print(iarr, strarr);
	print(iarr);
	return 0;
}
