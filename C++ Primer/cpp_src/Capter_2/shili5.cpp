#include<iostream>

int main(void)
{
	int value = 24;
	int* const pvalue = &value;

	std::cout << *pvalue << std::endl;
	*pvalue = 89;
	std::cout << *pvalue << std::endl;

	int value_fuck = 0;
	//pvalue = &value_fuck;//����pvalue��һ��constָ�룬���������ܱ��޸ģ���������ָ��Ķ����ǿ����޸ĵ�

	return 0;
}
