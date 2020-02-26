#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
using namespace::std;

bool compare(const int* parr1, const int* parr2, int size1, int size2)//参数列表：数组名1，数组名2，数组1的大小，数组2的大小
{
	if (size1 == size2)
	{
		for (auto * ptr1 = parr1, *ptr2 = parr2; ptr1 != parr1 + size1; ++ptr1, ++ptr2)
			if (*ptr1 != *ptr2)
				return false;
		return true;
	}
	else
		return false;
}

bool compare(const int* parr1, const int* parr2, const int* end1, const int* end2)//参数列表：数组名1，数组名2，数组1的尾后指针，数组2的尾后指针
{
	if (end1 - parr1 == end2 - parr2)
	{
		for (auto* ptr1 = parr1, *ptr2 = parr2; ptr1 != end1; ++ptr1, ++ptr2)
			if (*ptr1 != *ptr2)
				return false;
		return true;
	}
	else
		return false;
}

int main(void)
{
	int arr1[10] = { 1,2 };
	int arr2[10] = { 1,2, };
	if (compare(arr1, arr2, end(arr1) - begin(arr1), end(arr2) - begin(arr2)))
		cout << "They are the same" << endl;
	else
		cout << "They are different!" << endl;

	if (compare(arr1, arr2, end(arr1), end(arr2)))
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	return 0;
}
