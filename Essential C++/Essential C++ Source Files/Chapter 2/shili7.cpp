#include<iostream>
#include<vector>
using namespace std;

void swap_value(int& value_1, int& value_2);	/*��Щ�ط������õ��ˡ����á����������ò�����ָ���������һ�㲻ͬ�ģ�
												��Ȼԭ������ͬ�ĵ������ǲ�һ����
													ָ�������ʹ��ָ��ָ����һ������
													�����ò�����ʹ�����ã�һ����ʶ����������һ���������������ý��в�����ʵ���Ƕ�ԭʼ��
																����ֱ�Ӳ�����
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
