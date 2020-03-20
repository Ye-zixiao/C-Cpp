#include<iostream>
#include<string>
#include"Sales_data.h"

std::istream& operator>>(std::istream&is,Sales_data&item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& operator<<(std::ostream&os,const Sales_data&item)
{
	return os << '\t' << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

const Sales_data& Sales_data::operator=(const Sales_data& item)
{
	bookNo = item.bookNo;
	units_sold = item.units_sold;
	revenue = item.revenue;
	return *this;
}

bool isShorter_Isbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn() ? true : false;
}

Sales_data& operator+(Sales_data&add,const Sales_data& item)
{
	add.units_sold += item.units_sold;
	add.revenue += item.revenue;
	return add;
}