#include<iostream>
#include<string>
#include<vector>
using namespace::std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream& read(istream& input, Sales_data& item);
string isbn(const Sales_data& item);
void combine(Sales_data& litem, const Sales_data& ritem);
ostream& print(ostream& output, const Sales_data& item);

int main(void)
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (isbn(total) == isbn(trans))
				combine(total, trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
	    cerr << "No data?" << endl;
	    return -1;
	}

	return 0;
}

istream& read(istream& input, Sales_data& item)
{
	input >> item.bookNo >> item.units_sold >> item.revenue;//每本的售价,这里应该设计成price的
	return input;
}

string isbn(const Sales_data& item)
{
	return item.bookNo;
}

void combine(Sales_data& litem, const Sales_data& ritem)
{
	double total = litem.revenue * litem.units_sold + ritem.revenue * ritem.units_sold;
	litem.units_sold += ritem.units_sold;
	litem.revenue = total / static_cast<double>(litem.units_sold);
	return;
}

ostream& print(ostream& output, const Sales_data& item)
{
	output << "\tBookNo:" << item.bookNo << "\n\t"
		<< "units have sold:" << item.units_sold << "\n\t"
		<< "revenue:" << item.revenue << endl;
	return output;
}
