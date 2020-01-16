#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

template<typename iteratortype, typename elemtype>
iteratortype find_elem(iteratortype first, iteratortype last, const elemtype& value);//泛型算法：查找

int main(void)
{
	const int arr[4] = { 1,2,3,4 };
	list<int> arr_list(arr, arr + 4);
	int value = 3;

	//对于list容器的查找
	if (find_elem(arr_list.begin(), arr_list.end(), value)!=arr_list.end())/*如果返回的泛型指针（迭代器）等于list类对象
																		   的最后一个元素的下一个位置，那么说明遍历整个
																		   容器list都没有找到这个value数*/
		cout << "Find" << endl;
	else
		cout << "Not find" << endl;

	//对于普通的数组的查找
	value = 6;
	if (find_elem(arr, arr + 4, value) != arr + 4)
		cout << "array:Find" << endl;
	else
		cout << "array:Not find" << endl;
	return 0;
}

template<typename iteratortype, typename elemtype>
iteratortype find_elem(iteratortype first, iteratortype last, const elemtype& value)
{
	for (; first != last; first++)
		if (value == *first)
			return first;
	return last;
}
