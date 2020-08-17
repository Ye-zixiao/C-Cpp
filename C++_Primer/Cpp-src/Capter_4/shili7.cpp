#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	double hello = 3.14;
	const double* phello = &hello;
	void* ptest = static_cast<void*>(const_cast<double*>(phello));
	double* pfinal = static_cast<double*>(ptest);
	double* pfinal_reinter = reinterpret_cast<double*>(ptest);
	cout << *pfinal << ' ' << *pfinal_reinter << endl;

	const double* pconst = const_cast<const double*>(pfinal);//使用const_cast可以为一个对象去掉底层const或者加上底层const的性质
	cout << *pconst << endl;

	return 0;
}
