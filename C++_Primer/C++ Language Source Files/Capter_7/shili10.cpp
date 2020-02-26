#include<iostream>
#include<string>
using namespace::std;

class Sales_data {

	friend istream& read(Sales_data& item, istream& is);
	friend ostream& print(const Sales_data& item, ostream& os);

public:
	Sales_data() = default;
	Sales_data(const string&str):bookNo(str){}
	Sales_data(const Sales_data&item):
		bookNo(item.bookNo),units_sold(item.units_sold),revenue(item.revenue){}
	Sales_data(const string&str,unsigned int n,double p):
		bookNo(str),units_sold(n),revenue(p*n){}
	Sales_data(istream& is) { read(*this, is); }

	double avg_price(void) const;
	string isbn(void) const { return bookNo; }
	Sales_data& combine(const Sales_data& item);

private:
	string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0;
};

inline double Sales_data::avg_price(void) const
{
    return units_sold ? revenue / units_sold : 0;
}

istream& read(Sales_data& item, istream& is=cin)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

ostream& print(const Sales_data& item, ostream& os=cout)
{
	os << "\tbookNo:" << item.bookNo << "\n\tunits_sold"
		<< item.units_sold << "\n\trevenue:" << item.revenue
		<< "\n\tavg_price:" << item.avg_price() << endl;
	return os;
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data item(lhs);
	return item.combine(rhs);
}

int main(void)
{
	Sales_data total(cin);
	if (cin)
	{
		Sales_data trans;
		while (read(trans))
		{
			if (trans.isbn() == total.isbn())
				//total = add(total, trans);//使用编译器合成的赋值操作
				total.combine(trans);
			else
			{
				print(total);
				total = trans;//使用编译器合成的赋值操作
			}
		}
		print(total);
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}
	return 0;
}
