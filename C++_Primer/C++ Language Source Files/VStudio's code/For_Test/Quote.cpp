#include"Quote.h"

/*-----------------------����ĳ�Ա����------------------------*/

std::string
Quote::isbn(void) const {
	return bookNo;
}

double 
Quote::net_price(std::size_t n) const {
	return price * n;
}

//ԭ����
double
Bulk_Quote::net_price(std::size_t n) const {
	return n >= min_cnt ? (1 - discount) * price * n : price * n;
}
//��ϰ���²���
//double
//Bulk_Quote::net_price(std::size_t n) const {
//	double non_over = (1 - discount) * price * n;//�����Ƿ񳬳�������δ�����ķ�ʽ���㣬�������˾Ͳ���ȥ�����Ĳ���
//	return n <= min_cnt ? non_over : non_over + (n - min_cnt) * price * discount;
//}

//��ʵû�б�ҪΪ���ر���﷨��ʹ���������������ʹ��if-else���������Լ�࣬��ô������if-else
//double
//Bulk_Quote::net_price(std::size_t n) const {
//	if (n >= min_cnt)
//		return min_cnt * price * (1 - discount) + (n - min_cnt) * price;
//	else
//		return min_cnt * price * (1 - discount);
//}


/*-----------------------�ǳ�Ա����------------------------*/

void print_total(std::ostream& os, const Quote& item, std::size_t n) {
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << item.net_price(n) << std::endl;
}