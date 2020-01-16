#include<iostream>
#include<vector>
using namespace std;

void swap_value(int& value_1, int& value_2);	/*这些地方都是用到了“引用”操作，引用操作与指针操作是有一点不同的，
												虽然原理是相同的但概念是不一样。
													指针操作：使得指针指向了一个对象
													而引用操作：使得引用（一个标识符）代表了一个对象，这样对引用进行操作其实就是对原始的
																对象直接操作。
													*/
void show_vec(const vector<int>& vec);
void bubble_sort(vector<int>& vec);

int main(void)
{
	int arr[8] = { 2,3,6,4,3,1,87,32 };
	vector<int> vec(arr, arr + 8);
	show_vec(vec);
	bubble_sort(vec);
	show_vec(vec);

	return 0;
}

void swap_value(int& value_1, int& value_2)
{
	int temp = value_1;
	value_1 = value_2;
	value_2 = temp;
}

void show_vec(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void bubble_sort(vector<int>& vec)
{
	int i, j;
	for (i = 0; i < vec.size(); i++)
		for (j = vec.size() - 1; j > 0; j--)
			if (vec[j - 1] > vec[j])
				swap_value(vec[j - 1], vec[j]);
}
