#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
	vector<size_t> stvec;
	for (size_t i = 0; i < 10; ++i)
		stvec.insert(stvec.begin(), i);
	for (const auto& elem : stvec)
		cout << elem << ' ';
	cout << endl;

	return 0;
}