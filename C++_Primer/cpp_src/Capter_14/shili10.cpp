#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace::std;
using namespace std::placeholders;

int main(void)
{
	vector<int> ivec, ivec_cpy;
	for (size_t i = 0; i < 10; ++i)
		ivec.push_back(i);
	transform(ivec.begin(), ivec.end(),ivec.begin(), bind(multiplies<int>(), _1, 2));
	for_each(ivec.cbegin(), ivec.cend(), [](int value) {cout << value << ' '; });
	cout << endl;

	return 0;
}
