#include<iostream>
#include<random>
using namespace::std;

int main(void)
{
	uniform_int_distribution<unsigned> uni_dis(0, 9);
	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
		cout << uni_dis(e) << ' ';
	cout << e.min() << ' ' << e.max() << endl;

	return 0;
}
