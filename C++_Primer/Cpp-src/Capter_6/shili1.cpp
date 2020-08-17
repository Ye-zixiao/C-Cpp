#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
//#include"Sales_item.h"
#include<stdexcept>
using namespace::std;

int fact(int value)
{
	return value > 1 ? fact(value - 1)*value : value;
}

int abs_value(int value)
{
	return value > 0 ? value : -value;
}

int main(void)
{
	string prompt= "Please enter a value(0<value<=10) for this program(Ctr+Z to quit): ";
	int value;
	for (int value; cout << prompt, cin >> value;)
	{
		if (value < 1 || value > 10)
		{
			cout << "out of range" << endl;
			continue;
		}
		cout << value << "!=" << fact(value) << endl;
	}
	return 0;
}
