#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
//#include"Sales_item.h"
#include<stdexcept>
using namespace::std;

int main(void)
{
	int value1, value2;
	cout << "Please enter two numbers:";
	while (cin >> value1 >> value2)
	{
		try {
			if (value2 == 0)
				throw runtime_error("value2 can't be 0");
			cout << value1 / value2 << endl;
		}
		catch (runtime_error err) {
			cout << err.what() << "\nDo you want to reinput(y/n)? ";
			char c;
			if (cin >> c || tolower(c) != 'n')
				continue;
			else
				break;
		}
		cout << "Keep enter two numbers:";
	}

	return 0;
}
