#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

void print(const vector<int>& ivec);			//��ӡ����������Ԫ��
void print_near(const vector<int>& ivec);		//��ӡ������ǰ�������3λ��Ԫ�غ�
void print_front_back(const vector<int>& ivec);	//��ӡ������ͷβ��1λ��Ԫ�غ�

int main(void)
{
	vector<int> ivec(10);
	int num = 0;
	for (auto& i : ivec)
	{
		i = num;
		num += 3;
	}

	print(ivec);
	print_near(ivec);
	print_front_back(ivec);

	return 0;
}

void print(const vector<int>& ivec)
{
	for (auto& i : ivec)
		cout << i << ' ';
	cout << endl;
	return;
}

void print_near(const vector<int>& ivec)
{
	if (ivec.size() == 1)
		cout << ivec[0];
	else if (ivec.size() > 1)
	{
		for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
		{
			if (iter == ivec.begin())
				cout << *iter + *(iter + 1) << ' ';
			else if (iter == ivec.end() - 1)
				cout << *iter + *(iter - 1) << ' ';
			else
				cout << *iter + *(iter - 1) + *(iter + 1) << ' ';
		}
		cout << endl;
	}
	return;
}

void print_front_back(const vector<int>& ivec)
{
	auto begin_iter = ivec.begin(), end_iter = ivec.end() - 1;
	while (begin_iter < end_iter)
		cout << *(begin_iter++)+*(end_iter--) << ' ';
	cout << *begin_iter << endl;
	return;
}
