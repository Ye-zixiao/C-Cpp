#include<iostream>
#include<fstream>
#include<string>
#include"Sales_data.h"
using namespace::std;

int main(int argc,char *args[])
{
	ifstream in(args[1]);
	ofstream out(args[2]);
	Sales_data total;
	if (read(total, in))
	{
		Sales_data trans;
		while (read(trans, in))
		{
			if (trans.isbn() == total.isbn())
				total.combine(trans);
			else
			{
				print(total, out)<<endl;
				total = trans;
			}
		}
		print(total, out)<<endl;
		in.clear();

		return 0;
	}
	else
	{
		in.clear();
		cerr << "No data?" << endl;
		return -1;
	}
}
