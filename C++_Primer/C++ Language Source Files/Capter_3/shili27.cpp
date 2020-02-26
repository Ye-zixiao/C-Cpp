#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

void init_arr(int* parr, const vector<int>& ivec, int size);

int main(void)
{
	int int_arr[] = { 1,2,3,4,5,6,7 };
	vector<int> ivec(begin(int_arr), end(int_arr));//使用数组初始化vector
	for (auto i : ivec)
		cout << i << ' ';
	cout << endl;

	constexpr unsigned size = 10;
	int copy_arr[size];
	init_arr(copy_arr, ivec, size);

	for (size_t i = 0; i < size; i++)
		cout << copy_arr[i] << ' ';
	cout << endl;

	return 0;
}

void init_arr(int* parr, const vector<int>& ivec,int size)
{
	for (unsigned cnt = 0; cnt < size; ++cnt)
	{
		if (cnt < ivec.size())//当数组的长度小于向量长度，那么就用向量中前面的部分去初始化数组
			parr[cnt] = ivec[cnt];
		else
			parr[cnt] = 0;  //当数组的长度大于向量长度，那么就用给向量中的所有元素去初始化数组，然后将数组的后半部分用0初始化
	}
}
