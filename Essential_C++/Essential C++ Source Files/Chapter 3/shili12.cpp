#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int> filter(const vector<int>& vec, int value, less<int>& lt);
void display(const vector<int>& vec);

int main(void)
{
	int arr[6] = { 2,5,8,11,5,12 };
	vector<int> s_vec(arr, arr + 6);
	vector<int> d_vec;

	int value = 9;
	less<int> lessInt;						//函数对象是类的实例对象！！！！所以传进的参数也是传递实例对象
	d_vec = filter(s_vec, value,lessInt);
	display(d_vec);

	return 0;
}

vector<int> filter(const vector<int>& vec, int value, less<int>& lt)
{
	vector<int> nvec;
	typename vector<int>::const_iterator it = vec.begin();

	while ((it = find_if(it, vec.end(), bind2nd(lt, value))) != vec.end())
	{
		nvec.push_back(*it);
		it++;
	}
	return nvec;
}

void display(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
}
