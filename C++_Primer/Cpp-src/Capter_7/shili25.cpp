#include<iostream>
#include<string>
using namespace::std;

class Sales_data {
	friend std::istream& read(Sales_data& item, std::istream& is);
	friend std::ostream& print(const Sales_data& item, std::ostream& os);
public:
	Sales_data(const std::string& bn, unsigned cnt, double price) ://���캯��1
		bookNo(bn), units_sold(cnt), revenue(price* units_sold)
	{
		std::cout << "Sales_data(const std::string& bn, unsigned cnt, double price)//���캯��1" << std::endl;
	}
	Sales_data() :Sales_data("", 0, 0)
	{
		std::cout << "Sales_data()//���캯��2" << std::endl;
	}//���캯��2
	Sales_data(const std::string& bn) :Sales_data(bn, 0, 0)
	{
		std::cout << "Sales_data(const std::string& bn)//���캯��3" << std::endl;
	}//���캯��3
	Sales_data(std::istream& is) :Sales_data()
	{
		std::cout << "Sales_data(std::istream& is)//���캯��4" << std::endl;
		read(*this, is);
	}//���캯��4

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
    Sales_data test_1;//�ȴ�ӡ���캯��1��Ȼ���ӡ���캯��2
    cout << endl;
    Sales_data test_2("test", 2, 2);//ֻ���ӡ���캯��1
    cout << endl;
    Sales_data test_3("test");//��ӡ���캯��1��Ȼ���ӡ���캯��3
    cout << endl;
    Sales_data test_4(cin);//�ȴ�ӡ���캯��1��Ȼ���ӡ���캯��2��Ȼ���ӡ���캯��4
    cout << endl;

    return 0;
}
