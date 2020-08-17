#include<iostream>
#include<string>
#include<vector>
//#include"header.h"
using namespace::std;

struct Sales_data {
	Sales_data() = default;
	Sales_data(const string&s):bookNo(s){}
	Sales_data(const string&s,unsigned n,double p):
		bookNo(s),units_sold(n),revenue(n*p){}
	Sales_data(istream& is)
	{
		double price;
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
		//read(is, *this);//这种方法很容易错误，因为对于Sales_data这个类的定义而言，read是不可见的
		//而若将read的函数声明放到Sales_data类定义的前面反而对于read函数而言Sales_data又不可见
	}
	double avg_price(void) const;

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

double Sales_data::avg_price(void) const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
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

int main(void)
{
	Sales_data test("test", 3, 12);
	print(cout, test) << endl;

	Sales_data test_1("testfor");
	print(cout, test_1) << endl;

	Sales_data test_2(cin);
	print(cout, test_2) << endl;

	Sales_data test_3;
	print(cout, test_3) << endl;

	return 0;
}
