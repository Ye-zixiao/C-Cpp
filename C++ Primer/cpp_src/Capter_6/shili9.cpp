#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

const int& fuck_value(const int value)
{
	//static int test_value = value;
	static int test_value=value;
	test_value++;

	return test_value;
}

int main(void)
{
	cout << fuck_value(5) << endl;

	return 0;
}
