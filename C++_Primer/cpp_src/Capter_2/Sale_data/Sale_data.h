#ifndef SALE_DATA_H
#define SAlE_DATA_H//定义预处理变量

#include<iostream>
#include<string>

struct Sale_data {
	std::string bookNo;
	unsigned units_sold;
	double revenue;
	double price;
};

bool sum_two_data(Sale_data& item1, Sale_data& item2)
{
	if (item1.bookNo == item2.bookNo)
	{
		unsigned totalCnt = item1.units_sold + item2.units_sold;
		double totalRevenue = item1.revenue + item2.revenue;
		std::cout << item1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt)
			std::cout << totalRevenue / totalCnt << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
		return true;
	}
	else
	{
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return false;
	}
}

void input_data(Sale_data& item)
{
	std::cout << "Enter the bookNo: ";
	std::cin >> item.bookNo;
	std::cout << "price: ";
	std::cin >> item.price;
	std::cout << "units_sold: ";
	std::cin >> item.units_sold;
	item.revenue = item.price * item.units_sold;

	return;
}

#endif // !SALE_DATA_H
