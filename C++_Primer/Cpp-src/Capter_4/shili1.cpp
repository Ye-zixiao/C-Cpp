#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

void print(const vector<int>& ivec)
{
	for (auto& i : ivec)
		cout << i << ' ';
	cout << endl;
	return;
}

int main(void)
{
	vector<int> ivec(10);
	int cnt = 0;
	for (auto& i : ivec)
		i = cnt++;

	print(ivec);
	for (auto& i : ivec)
		i = (i % 2 == 0) ? i : i * 2;
	print(ivec);

	return 0;
}
