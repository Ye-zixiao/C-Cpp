#include"Sale_data.h"
#include<iostream>
#include<string>

int main(void)
{
	Sale_data item1, item2;
	//�����������ۼ�¼��
	std::cout << "Please enter two sale records:\n";
	input_data(item1);
	input_data(item2);
	sum_two_data(item1, item2);

	return 0;
}
