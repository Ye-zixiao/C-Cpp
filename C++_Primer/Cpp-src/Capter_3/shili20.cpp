#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
	vector<int> ivec(10, 42);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		*iter *= 2;

	for (auto con_iter = ivec.cbegin(); con_iter != ivec.cend(); ++con_iter)
		cout << *con_iter << ' ';
	cout << endl;

	return 0;
}
