#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<list>
using namespace::std;

int main(void)
{
	vector<int> ivec(10);
	list<int> il(10);
	for (size_t i = 0; i < 10; ++i)
	{
		ivec.push_back(i);
		il.push_back(i);
	}
	il.push_back(100);
	cout << ivec.size() << ' ' << il.size() << endl;
	//��ʵil�Ĵ�С�Ѿ������˸ı䣬����equal�㷨��Ĭ����Ϊ�����ȽϵĶ���Ĵ�С����ͬ��

	if (equal(ivec.cbegin(), ivec.cend(), il.cbegin()))
		cout << "eqaul" << endl;

	return 0;
}
