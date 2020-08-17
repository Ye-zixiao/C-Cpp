#include<iostream>
#include<random>
#include<ctime>
using namespace::std;

template<unsigned... be>
unsigned Random_Num(unsigned seed = time(0)) {
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> uni_dis(be...);
	return uni_dis(e);
}

unsigned Random_num(unsigned begin, unsigned end, unsigned seed = time(0)) {
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> uni_dis(begin, end);
	return uni_dis(e);
}

int main(void)
{
	for (size_t i = 0; i < 10; ++i) {
		for (size_t j = 0; j < 10; ++j)
			cout << Random_Num<0, 9>() << ' ';
		cout << endl;
	}cout << endl;

	for (size_t i = 0; i < 10; ++i) {
		for (size_t j = 0; j < 10; ++j)
			cout << Random_num(0, 9,32424243) << ' ';
		cout << endl;
	}

	return 0;
}
