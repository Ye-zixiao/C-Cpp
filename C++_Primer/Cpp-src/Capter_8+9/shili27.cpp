#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
	vector<int> ivec;
	for (size_t i = 0; i < 20; ++i)
	{
		ivec.push_back(1);
		cout << "size:" << ivec.size() << endl
			<< "capacity:" << ivec.capacity() << endl;

		while (ivec.size() != ivec.capacity())
			ivec.push_back(12);
		cout << "========================" << endl;
	}

	return 0;
}
