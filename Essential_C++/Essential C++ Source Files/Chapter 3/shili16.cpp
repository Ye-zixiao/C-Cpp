#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void display(const vector<int>& vec);
vector<int> sub_vec(const vector<int>& vec, int value);

int main(void)
{
	int arr[7] = { 1,3,4,7,5,4,8 };
	vector<int> vec(arr, arr + 7);

	int value = 5;
	vector<int> fil = sub_vec(vec, value);
	display(fil);

	return 0;
}

void display(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

vector<int> sub_vec(const vector<int>& vec, int value)
{
	vector<int> local_vec(vec);
	sort(local_vec.begin(), local_vec.end(), less<int>());

	vector<int>::iterator iter = find_if(local_vec.begin(),//�������ʹ����const_iterator�ͻᵼ�������erase����
                  local_vec.end(), bind2nd(greater<int>(), value));//��Ϊconstָ����ָ��Ķ����ǲ������޸ĵ�

	local_vec.erase(iter, local_vec.end());
	return local_vec;
}

