#include"Quote.h"

/*-----------------------基类的成员函数------------------------*/

std::string
Quote::isbn(void) const {
	return bookNo;
}

double 
Quote::net_price(std::size_t n) const {
	return price * n;
}

//原策略
double
Bulk_Quote::net_price(std::size_t n) const {
	return n >= min_cnt ? (1 - discount) * price * n : price * n;
}
//练习题新策略
//double
//Bulk_Quote::net_price(std::size_t n) const {
//	double non_over = (1 - discount) * price * n;//不管是否超出，先以未超出的方式计算，若超出了就补上去超出的部分
//	return n <= min_cnt ? non_over : non_over + (n - min_cnt) * price * discount;
//}

//其实没有必要为了特别的语法，使用条件运算符，若使用if-else能做到语言简洁，那么就是用if-else
//double
//Bulk_Quote::net_price(std::size_t n) const {
//	if (n >= min_cnt)
//		return min_cnt * price * (1 - discount) + (n - min_cnt) * price;
//	else
//		return min_cnt * price * (1 - discount);
//}


/*-----------------------非成员函数------------------------*/

void print_total(std::ostream& os, const Quote& item, std::size_t n) {
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << item.net_price(n) << std::endl;
}