#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<list>
using namespace::std;

int main(void)
{
	int value = 5;
	vector<int> ivec{ 1,2,5,4,5,6,7,8,9 };

	vector<int>::iterator iter = ivec.begin();
	while (iter != ivec.begin() + ivec.size() / 2)
	{
		if (*iter == value)
			iter = ivec.insert(iter, value*2) + 1;
		++iter;
	}

	for (const auto& elem : ivec)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
