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

	const double* pconst = const_cast<const double*>(pfinal);//ʹ��const_cast����Ϊһ������ȥ���ײ�const���߼��ϵײ�const������
	cout << *pconst << endl;

	return 0;
}
