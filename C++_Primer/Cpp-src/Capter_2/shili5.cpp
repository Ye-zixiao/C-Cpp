#include<iostream>

int main(void)
{
	int value = 24;
	int* const pvalue = &value;

	std::cout << *pvalue << std::endl;
	*pvalue = 89;
	std::cout << *pvalue << std::endl;

	int value_fuck = 0;
	//pvalue = &value_fuck;//由于pvalue是一个const指针，所以它不能被修改，但是它所指向的对象是可以修改的

	return 0;
}
