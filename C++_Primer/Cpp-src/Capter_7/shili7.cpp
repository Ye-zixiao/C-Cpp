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
		//read(is, *this);//���ַ��������״�����Ϊ����Sales_data�����Ķ�����ԣ�read�ǲ��ɼ���
		//������read�ĺ��������ŵ�Sales_data�ඨ���ǰ�淴������read��������Sales_data�ֲ��ɼ�
	}

	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& item);
	double avg_price(void) const;

	string bookNo;
	unsigned units_sold = 0;
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
	Sales_data total(cin);
	if (cin)
	{
		Sales_data trans;
		while (read(cin,trans))
		{
			if (trans.isbn() == total.isbn())
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
