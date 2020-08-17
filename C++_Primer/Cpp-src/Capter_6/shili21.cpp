#include<iostream>
#include<string>
#include<cassert>
using namespace::std;

void test(void)
{
	cout << "Test:" << __FILE__ << ": in function " << __func__
		<< " at line " << __LINE__ << endl
		<< "   Compilled on " << __DATE__ << endl
		<< " at " << __TIME__ << endl;
}

int main(void)
{
	test();
	return 0;
}
