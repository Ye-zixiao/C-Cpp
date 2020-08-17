#include<iostream>
#include<string>
//#define NDEBUG
#include<cassert>
using namespace::std;

void print_name(void)
{
#ifndef NDEBUG
	cout << __func__ << endl;
#endif
}

int main(void)
{
	print_name();

	return 0;
}
