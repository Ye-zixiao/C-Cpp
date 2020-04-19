#include"Sales_data.h"


std::istream& operator>>(std::istream&is,Sales_data&item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

std::ostream& operator<<(std::ostream&os,const Sales_data&item)
{
	return os << '\t' << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data& Sales_data::operator=(const Sales_data& item)
{
	bookNo = item.bookNo;
	units_sold = item.units_sold;
	revenue = item.revenue;
	return *this;
}

Sales_data&
Sales_data::operator=(const std::string& str) {
	bookNo = str;
	units_sold = 0;
	revenue = 0;
	return *this;
}

Sales_data& 
Sales_data::operator+=(const Sales_data& item) {
	if (item.bookNo != bookNo)
		throw std::runtime_error("Different Sales_data");
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

bool isShorter_Isbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn() ? true : false;
}

Sales_data 
operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp(lhs);
	temp += rhs;
	return temp;
}
