#include<iostream>
#include<memory>
#include<string>
using namespace::std;

int main(void)
{
	int value = 10, * pvalue = &value;
	{
	    unique_ptr<int> p(pvalue);
	    *p=100;
	}
	cout << *pvalue << endl;

	return 0;
}
