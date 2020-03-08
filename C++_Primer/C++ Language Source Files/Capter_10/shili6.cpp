#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
using namespace::std;

void print(const int (&arr)[10])
{
	for (const auto& elem : arr)
		cout << elem << ' ';
	cout << endl;
}



ostream& operator<<(ostream& os, const vector<int>& ivec)
{
	for (const auto& elem : ivec)os << elem << ' '; return os;
}

int main(void)
{
	int arr[10];
	int dest_arr[10];
	for (size_t i = 0; i < size(arr); ++i)
		arr[i] = i;

	copy(begin(arr), end(arr), begin(dest_arr));
	print(dest_arr);

	fill_n(begin(dest_arr), size(dest_arr), 10);//用10覆盖dest_arr中的所有元素
	print(dest_arr);
	vector<int> newvec;
	auto back_insert_iter = back_inserter(newvec);
	replace_copy(begin(dest_arr), end(dest_arr), back_insert_iter, 10, 32);
	cout << "newvec:" << newvec << endl;
	replace(begin(dest_arr), end(dest_arr), 10, 89);
	cout << "new dest_arr: "; print(dest_arr);

	return 0;
}

//int test_arr[sizeof(arr) / sizeof(*arr)];//sizeof运算符返回的是size_t类型的常量表达式
