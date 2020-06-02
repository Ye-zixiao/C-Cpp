#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace::std;

int main(void)
{
	Sales_data item1("hello", 1, 23.1), item2("fuck", 2, 12.2);
	try {
		item1 + item2;
	}
	catch (isbn_mismatch& err) {
		cerr << err.what() << endl
			<< "The left one is: " << err.left
			<< endl << "The right one is: " << err.right << endl;
	}

	return 0;
}
