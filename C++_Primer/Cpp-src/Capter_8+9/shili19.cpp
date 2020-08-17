#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<list>
using namespace::std;

void erase(vector<int>& ivec);
void erase(list<int>& ilist);
void print(const vector<int>& ivec);
void print(const list<int>& ilist);

int main(void)
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec(begin(ia), end(ia));
	list<int> ilist(begin(ia), end(ia));

	erase(ivec);
	erase(ilist);
	print(ivec);
	print(ilist);

	return 0;
}

void erase(vector<int>& ivec)
{
	auto iter = ivec.begin();
	while (iter != ivec.end())
		if (*iter % 2)//����ж���żҲ����ͨ��λ���㣬ͨ���鿴���һλ�����Ƿ�Ϊ1
			iter = ivec.erase(iter);
		else
			++iter;
}

void erase(list<int>& ilist)
{
	auto iter = ilist.begin();
	while (iter != ilist.end())
		if (*iter % 2)
			++iter;
		else
			iter = ilist.erase(iter);
}

void print(const list<int>& ilist)
{
	for (auto i : ilist)cout << i << ' ';
	cout << endl;
}

void print(const vector<int>& ivec)
{
	for (auto i : ivec)cout << i << ' ';
	cout << endl;
}
