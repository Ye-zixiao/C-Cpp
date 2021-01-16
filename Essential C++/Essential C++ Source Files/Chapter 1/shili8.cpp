#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int arr[3][2] = {
		{1,2,},{3,4},{5,6},
	};

	int arr_1[2] = { 11,22 };
	int arr_2[2] = { 33,44 };
	int arr_3[2] = { 55,66 };

	int* parr[3] = { arr_1,arr_2,arr_3 };

	//打印arr
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	//打印parr
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << *(*(parr + i) + j) << " ";
		cout << "\n";
	}
	cout << "\n";

	//再次打印arr
	for (int i = 0; i < 6; i++)
		cout << *(*arr+i) << " ";
	cout << "\n";

	/*二级指针和二维数组要区分，但是这个指针的指针这里是没问题的*/
	return 0;
}
