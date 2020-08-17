#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void)
{
	vector<int> ivec;
	auto biter = back_inserter(ivec);

	for (int i = 0; i < 10; i++)
		biter = i;
	for (const auto& elem : ivec)
		cout << elem << ' '; cout << endl;

	return 0;
}