#include<iostream>
#include<vector>
using namespace std;

template<typename elemtype>
const elemtype* find_elem(const elemtype* first, const elemtype* last,
	const elemtype& value);							//�÷����㷨�ĺ���˼����ǽ���ָ�루��ַ��ֱ�Ӷ����ݣ����������в��ң�������������������ʲô

template<typename elemtype>
inline elemtype* begin_elem(vector<elemtype>& vec);/*�������ĳ�const vector��������������Ϊ������Ϊ��
														�п����ƻ���ԭʼ���ݣ�����ȫ�����ʲ���ͨ������*/

template<typename elemtype>
inline elemtype* end_elem(vector<elemtype>& vec);

int main(void)
{
	int arr[4] = { 1,2,3,4 };
	vector<int> vec_arr(arr, arr + 4);
	int value = 5;
	if(!find_elem(arr,arr+4,value))//��������ķ��Ͳ���
		cout<<"Not find!"<<endl;
	else
		cout<<"Find"<<endl;
	if (!find_elem(begin_elem(vec_arr), end_elem(vec_arr), value))//����vector�ķ��Ͳ���
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
