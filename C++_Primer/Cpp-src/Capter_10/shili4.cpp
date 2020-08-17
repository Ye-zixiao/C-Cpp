#include<iostream>
#include<vector>
#include<numeric>
using namespace::std;

int main(void)
{
	vector<double> dvec(10);
	for (size_t i = 0; i < dvec.size(); ++i)
		dvec[i] = i + 0.02;

	cout << accumulate(dvec.cbegin(), dvec.cend(), 0) << endl;//»¹ÊÇ45£¡

	return 0;
}
