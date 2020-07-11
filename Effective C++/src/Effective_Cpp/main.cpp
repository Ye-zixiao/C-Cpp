#include<iostream>
#include"Test.h"

int main(void)
{
	Test* ptest(Test::creator(12, Test::C1));
	std::cout << ptest->get() << std::endl;
	std::cout << ptest->modify(452).get() << std::endl;
	delete ptest;

	return 0;
}