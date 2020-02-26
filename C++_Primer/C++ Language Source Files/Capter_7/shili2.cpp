#include<iostream>
#include<string>
#include<vector>
using namespace::std;

struct Sales_data {
	string isbn(void) const { return bookNo; }
	Sales_data& combine(const Sales_data& item);
	double avg_price(void) const;

	string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0;
};

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

double Sales_data::avg_price(void) const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

istream& read(istream& input, Sales_data& item)
{
	input >> item.bookNo >> item.units_sold >> item.revenue;
	return input;
}

ostream& print(ostream& output, const Sales_data& item)
{
	output << "\tbookNo:" << item.bookNo << "\n\tunits sold:"
		<< item.units_sold << "\n\trevenue:" << item.revenue
		<< "\n\tavg_price:" <<item.avg_price() << endl;
	return output;
}

int main(void)
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}

	return 0;
}
