#include<iostream>
#include<string>
#include"Share_ptr.h"
using namespace::std;
using nsp::Share_ptr;

int main(void)
{
	Share_ptr<string> sp(new string("hello"));
	cout << *sp << endl;

	return 0;
}
