#include<list>
#include<deque>
#include<stdexcept>
#include<vector>
#include<iostream>
using namespace::std;

int main(void)
{
	vector<double> dvec(10, 1.2);
	vector<int> ivec(dvec.cbegin(), dvec.cend());

	for (const auto& elem : ivec)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
