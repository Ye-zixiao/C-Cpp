#ifndef _SALES_DATA_
#define _SALES_DATA_

#include<iostream>
#include<string>

class Sales_data {
	friend std::istream& operator>>(std::istream&is,Sales_data&item);
	friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);
	friend Sales_data& operator+(Sales_data& add ,const Sales_data& item);
public:
	Sales_data(const std::string& bn, unsigned cnt, double price) :
		bookNo(bn), units_sold(cnt), revenue(price* units_sold) {}
	Sales_data() :Sales_data("", 0, 0) {}
	explicit Sales_data(const std::string& bn) :Sales_data(bn, 0, 0) {}
	//explicit Sales_data(std::istream& is) :Sales_data() {//关键字explicit禁止转换构造函数的使用（即禁止当前类类型的隐式的类类型转换）
	//	read(*this, is);
	//}

	Sales_data& operator=(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

	std::string isbn(void)const { return bookNo; }
	Sales_data& combine(const Sales_data& item);
	unsigned get_units_sold(void)const { return units_sold; }

private:
	double avg_price(void)const { return units_sold > 0 ? (revenue / units_sold) : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

//对于非成员函数需要在头文件中声明一下，而对于类中的成员函数而言其成员函数的声明早已经在头文件中声明过了
//对于类的成员函数不要使用extern关键字指明成员函数是定义在何处
extern std::istream& operator>>(std::istream&is,Sales_data&item);
extern std::ostream& operator<<(std::ostream& os, const Sales_data& item);
extern bool isShorter_Isbn(const Sales_data& lhs, const Sales_data& rhs);
extern Sales_data& operator+(Sales_data&add ,const Sales_data& item);

#endif