#include<iostream>
#include<vector>
using namespace std;

template<typename elemtype>
const elemtype* find_elem(const elemtype* first, const elemtype* last,
	const elemtype& value);							//该泛型算法的核心思想就是借用指针（地址）直接对数据（容器）进行查找，而不在意数据类型是什么

template<typename elemtype>
inline elemtype* begin_elem(vector<elemtype>& vec);/*如果这里改成const vector。。编译器会认为这种行为很
														有可能破坏了原始数据（不安全），故不会通过编译*/

template<typename elemtype>
inline elemtype* end_elem(vector<elemtype>& vec);

int main(void)
{
	int arr[4] = { 1,2,3,4 };
	vector<int> vec_arr(arr, arr + 4);
	int value = 5;
	if(!find_elem(arr,arr+4,value))//对于数组的泛型操作
		cout<<"Not find!"<<endl;
	else
		cout<<"Find"<<endl;
	if (!find_elem(begin_elem(vec_arr), end_elem(vec_arr), value))//对于vector的泛型操作
		cout << "Not find" << endl;
	else
		cout << "Find" << endl;

	return 0;
}

template<typename elemtype>
const elemtype* find_elem(const elemtype* first, const elemtype* last,
	const elemtype& value)
{
	if (!first || !last || first > last)
		return 0;
	else
	{
		for (; first <= last; first++)
			if (*first == value)
				return first;
		return 0;
	}
}

template<typename elemtype>
inline elemtype* begin_elem(vector<elemtype>& vec)
{
	return vec.empty() ? 0 : &vec[0];
}

template<typename elemtype>
inline elemtype* end_elem(vector<elemtype>& vec)
{
	return vec.empty() ? 0 : &vec[vec.size() - 1];
}
