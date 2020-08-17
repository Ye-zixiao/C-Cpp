#include<iostream>
#include<string>
using namespace::std;

class Sales_data {
	friend std::istream& read(Sales_data& item, std::istream& is);
	friend std::ostream& print(const Sales_data& item, std::ostream& os);
public:
	Sales_data(const std::string& bn, unsigned cnt, double price) ://构造函数1
		bookNo(bn), units_sold(cnt), revenue(price* units_sold)
	{
		std::cout << "Sales_data(const std::string& bn, unsigned cnt, double price)//构造函数1" << std::endl;
	}
	Sales_data() :Sales_data("", 0, 0)
	{
		std::cout << "Sales_data()//构造函数2" << std::endl;
	}//构造函数2
	Sales_data(const std::string& bn) :Sales_data(bn, 0, 0)
	{
		std::cout << "Sales_data(const std::string& bn)//构造函数3" << std::endl;
	}//构造函数3
	Sales_data(std::istream& is) :Sales_data()
	{
		std::cout << "Sales_data(std::istream& is)//构造函数4" << std::endl;
		read(*this, is);
	}//构造函数4

    const Sales_data& operator=(const Sales_data&item);

	std::string isbn(void)const { return bookNo; }
	const Sales_data& combine(const Sales_data& item);

private:
	double avg_price(void)const { return units_sold > 0 ? (revenue / units_sold) : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

std::istream& read(Sales_data& item, std::istream& is)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(const Sales_data& item, std::ostream& os)
{
	return os << '\t' << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
}

const Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

const Sales_data& Sales_data::operator=(const Sales_data&item)
{
	bookNo = item.bookNo;
	units_sold = item.units_sold;
	revenue = item.revenue;
	return *this;
}

int main(void)
{
    Sales_data test_1;//先打印构造函数1，然后打印构造函数2
    cout << endl;
    Sales_data test_2("test", 2, 2);//只会打印构造函数1
    cout << endl;
    Sales_data test_3("test");//打印构造函数1，然后打印构造函数3
    cout << endl;
    Sales_data test_4(cin);//先打印构造函数1，然后打印构造函数2，然后打印构造函数4
    cout << endl;

    return 0;
}
