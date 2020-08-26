#include<iostream>

int main(void)
{
	const int value = 10;
	const int* const pvalue = &value;
	auto ppvalue = pvalue;

	const int con_value = 0;
	ppvalue = &con_value;

	int mu_value = 0;
	ppvalue = &mu_value;
	//*ppvalue = 10;这段代码是错误的，说明ppvalue一致在初始化之后就有了const int* 的性质，是底层const


	return 0;
}
