#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

template<typename ElemType>//这个模板函数还不够完善
vector<ElemType> filter(const vector<ElemType>& vec, ElemType value);//模板缺点只能针对vector类对象
                                                                    //不能对普通数组处理
template<typename ElemType>
void display(const vector<ElemType>& vec);

int main(void)
{
	int arr[7] = { 1,3,4,7,5,4,8 };
	vector<int> vec(arr, arr + 7);

	int value = 6;
	vector<int> fil = filter(vec, value);
	display(fil);

	cout<<count(fil.begin(),fil.end(),4)<<endl;

	return 0;
}

template<typename ElemType>
vector<ElemType> filter(const vector<ElemType>& vec, ElemType value)
{
	vector<ElemType> local_vec(vec);
	sort(local_vec.begin(), local_vec.end());

	typename vector<ElemType>::iterator iter = find_if(local_vec.begin(),
		local_vec.end(), bind2nd(greater<ElemType>(), value));

	local_vec.erase(iter, local_vec.end());
	return local_vec;
}

template<typename ElemType>
void display(const vector<ElemType>& vec)
{
	typename vector<ElemType>::const_iterator iter = vec.begin();
	for (; iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
