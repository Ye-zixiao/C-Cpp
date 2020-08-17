#include<iostream>
#include<string>
using namespace::std;

class Sales_data {
	friend std::istream& read(Sales_data& item, std::istream& is);
	friend std::ostream& print(const Sales_data& item, std::ostream& os);
public:
	Sales_data(const std::string& bn, unsigned cnt, double price) :
		bookNo(bn), units_sold(cnt), revenue(price* units_sold) {}
	Sales_data() :Sales_data("", 0, 0) {}
	Sales_data(const std::string& bn) :Sales_data(bn, 0, 0) {}
	Sales_data(std::istream& is) :Sales_data() { read(*this, is); }

	std::string isbn(void)const { return bookNo; }
	const Sales_data& combine(const Sales_data& item);

private:
    double avg_price(void)const {return units_sold>0?(revenue/units_sold):0;}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

std::istream& read(Sales_data& item, std::istream& is = std::cin)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(const Sales_data& item, std::ostream& os = std::cout)
{
	return os << '\t' << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue<<' '<<item.avg_price();
}

const Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
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
				total.combine(trans);
			else
			{
				print(total) << endl;
				total = trans;
			}
		}
		print(total) << endl;
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}

	return 0;
}
