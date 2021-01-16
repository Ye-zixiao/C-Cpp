#include<iostream>
#include<vector>
#include<list>
#include<array>
using namespace::std;

void print(const array<int, 10>& arr)
{
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}

void print(const vector<int>& ivec)
{
	for (const auto& elem : ivec)
		cout << elem << ' ';
	cout << endl;
}

void print(const list<int>& il)
{
	for (const auto& elem : il)
		cout << elem << ' ';
	cout << endl;
}

int main(void)
{
	vector<int> ivec_1{ 1,2,3,4,5 }, ivec_2{ 9,8,7,6,5 };
	vector<int>::const_iterator iter = ivec_1.begin();

	cout << "before swaping:" << *iter << endl;
	swap(ivec_1, ivec_2);
	cout << "after swaping:" << *iter << endl;//迭代器iter仍然指向ivec_1中的首元素

	array<int, 10> arr1{ 1,2,3,4,5 };
	array<int, 10> arr2{ 9,8,7,6,5 };
	array<int, 10>::const_iterator arr_iter = arr1.begin();

	cout << "before swaping:" << *arr_iter << endl;
	arr1.swap(arr2);
	cout << "after swaping:" << *arr_iter << endl;

	return 0;
}
