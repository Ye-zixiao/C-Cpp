#include<iostream>
#include<string>
using namespace::std;

struct Sales_data {
	string isbn(void) const { return bookNo; }
	double avg_price(void) const { return revenue / units_sold; }
	Sales_data& combine(const Sales_data& item);

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << "\tbookNo:" << item.bookNo << "\n\tunits_sold:"
		<< item.units_sold << "\n\trevenue:" << item.revenue
		<< "\n\tavg_price:" << item.avg_price() << endl;
	return os;
}

Sales_data add(const Sales_data& rhs, const Sales_data& lhs)
{
	Sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}

int main(void)
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (trans.isbn() == total.isbn())
				total.combine(trans);
			else
			{
				print(cout, total);
				trans = total;
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
