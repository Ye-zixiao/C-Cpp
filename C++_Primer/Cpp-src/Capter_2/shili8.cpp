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
	//*ppvalue = 10;��δ����Ǵ���ģ�˵��ppvalueһ���ڳ�ʼ��֮�������const int* �����ʣ��ǵײ�const


	return 0;
}
