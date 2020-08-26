#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace::std;

vector<unsigned> rand_Vec(void) {
	vector<unsigned> randvec;
	static uniform_int_distribution<unsigned> uni_dis;
	static default_random_engine e;
	for (size_t i = 0; i < 100; ++i)
		randvec.push_back(uni_dis(e));
	return randvec;
}

int main(void)
{
	vector<unsigned> randvec1(rand_Vec()), randvec2(rand_Vec());
	cout << (randvec1 == randvec2 ? "equal" : "not equal") << endl;

	cout << time(0) << endl;
	//cout << time() << endl;

	return 0;
}
