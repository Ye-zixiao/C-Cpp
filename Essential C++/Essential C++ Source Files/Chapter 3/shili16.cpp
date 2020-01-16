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

	vector<int>::iterator iter = find_if(local_vec.begin(),//如果这里使用了const_iterator就会导致下面的erase报错，
                  local_vec.end(), bind2nd(greater<int>(), value));//因为const指针所指向的对象是不能做修改的

	local_vec.erase(iter, local_vec.end());
	return local_vec;
}

