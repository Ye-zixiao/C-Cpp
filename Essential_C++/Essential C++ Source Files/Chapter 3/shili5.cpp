#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

template<typename iteratortype, typename elemtype>
iteratortype find_elem(iteratortype first, iteratortype last, const elemtype& value);//�����㷨������

int main(void)
{
	const int arr[4] = { 1,2,3,4 };
	list<int> arr_list(arr, arr + 4);
	int value = 3;

	//����list�����Ĳ���
	if (find_elem(arr_list.begin(), arr_list.end(), value)!=arr_list.end())/*������صķ���ָ�루������������list�����
																		   �����һ��Ԫ�ص���һ��λ�ã���ô˵����������
																		   ����list��û���ҵ����value��*/
		cout << "Find" << endl;
	else
		cout << "Not find" << endl;

	//������ͨ������Ĳ���
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
