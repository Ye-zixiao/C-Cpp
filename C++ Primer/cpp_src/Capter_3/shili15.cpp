#include<iostream>
#include<vector>
using namespace::std;

void input_int(vector<int>& v);
void print(vector<int>& v);
void print_near(vector<int>& v);//��ӡÿһ��Ԫ�ص��ٽ���
void print_front_back(vector<int>& v);//��ӡ������ǰ�����Ԫ�صĺ�
void print_test(vector<int>& v);

int main(void)
{
	vector<int> ivec;
	input_int(ivec);

	print_near(ivec);
	print_front_back(ivec);
	print_test(ivec);

	return 0;
}

void input_int(vector<int>& v)
{
	int value;
	while (cin >> value)
		v.push_back(value);
	return;
}

void print(vector<int>& v)
{
	for (const int value : v)
		cout << value << " ";
	cout << endl;
	return;
}

void print_near(vector<int>& v)
{
	if (v.size() == 1)
		cout << v[0] << endl;
	else if(v.size()>1)
	{
		for (decltype(v.size()) cnt = 0; cnt < v.size(); ++cnt)
		{
			if (!cnt)
				cout << v[cnt] + v[cnt+1];
			else if (cnt == v.size() - 1)
				cout << v[cnt] + v[cnt - 1];
			else
				cout << v[cnt - 1] + v[cnt + 1] + v[cnt];
			cout << ' ';
		}
		cout << endl;
	}

	return;
}

void print_front_back(vector<int>& v)
{
	if (v.size())
	{
		for (decltype(v.size()) cnt = 0; cnt < v.size() / 2; ++cnt)
			cout << v[cnt] + v[v.size() - cnt - 1] << ' ';
		if (v.size() % 2)
			cout << v[v.size() / 2] << ' ';
		cout << endl;
	}

	return;
}

void print_test(vector<int>& v)//�����㷨��ʵ����࣬��������渴�ӵķ����Եø���
{
    int m = 0;
	int n = v.size() - 1;
	while (m < n)
	{
		cout << v[m] + v[n] << endl;
		++m;
		--n;
	}
	if(m==n)
        cout<<v[m]<<endl;
}
