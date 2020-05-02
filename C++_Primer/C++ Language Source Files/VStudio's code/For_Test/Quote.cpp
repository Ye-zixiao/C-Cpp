#include"Quote.h"
//#define DEBUG
/*-----------------------基类的成员函数------------------------*/

String
Quote::isbn(void) const {
	return bookNo;
}

double
Quote::net_price(std::size_t n) const {
	return n * price;
}

Quote::Quote(const Quote& item) :
	bookNo(item.bookNo), price(item.price) {
#ifdef DEBUG
	std::cout << "Quote(const Quote&)" << std::endl;
#endif
}

Quote::Quote(Quote&& item) noexcept :
	bookNo(std::move(item.bookNo)), price(std::move(item.price)) {
#ifdef DEBUG
	std::cout << "Quote(Quote&&)" << std::endl;
#endif
}

Quote::~Quote() {
#ifdef DEBUG
	std::cout << "~Quote()" << std::endl;
#endif
}

Quote&
Quote::operator=(const Quote& item) {
	if (this != &item){
		bookNo = item.bookNo;
		price = item.price;
	}
#ifdef DEBUG
	std::cout << "Quote& operator=(const Quote&)" << std::endl;
#endif
	return *this;
}

Quote&
Quote::operator=(Quote&& item)noexcept {
	if (this != &item){
		bookNo = std::move(item.bookNo);
		price = std::move(item.price);
	}
#ifdef DEBUG
	std::cout << "Quote& operator=(Quote&&)" << std::endl;
#endif
	return *this;
}

/*-----------------------派生类的成员函数------------------------*/

double
Bulk_Quote::net_price(std::size_t n) const {
	return n >= quantity ? n * price * (1 - discount) : n * price;
}

double
Mulk_Quote::net_price(std::size_t n) const {
	if (n >= quantity)
		return quantity * price * (1 - discount) + (n - quantity) * price;
	else
		return n * price * (1 - discount);
}

Disc_Quote::Disc_Quote(const Disc_Quote& item) :
	Quote(item), discount(item.discount), quantity(item.quantity) {
#ifdef DEBUG
	std::cout << "Disc_Quote(const Disc_Quote*)" << std::endl;
#endif
}

Disc_Quote::Disc_Quote(Disc_Quote&& item)noexcept :
	Quote(std::move(item)), discount(std::move(item.discount)), quantity(std::move(item.quantity)) {
#ifdef DEBUG
	std::cout << "Disc_Quote(Disc_Quote&&)" << std::endl;
#endif
}

Disc_Quote::~Disc_Quote() {
#ifdef DEBUG
	std::cout << "~Disc_Quote()" << std::endl;
#endif
}

Disc_Quote&
Disc_Quote::operator=(const Disc_Quote& item) {
	if (this != &item){
		Quote::operator=(item);
		discount = item.discount;
		quantity = item.quantity;
	}
#ifdef DEBUG
	std::cout << "Disc_Quote& operator=(const Disc_Quote&)" << std::endl;
#endif
	return *this;
}

Disc_Quote&
Disc_Quote::operator=(Disc_Quote&& item) noexcept {
	if (this != &item){
		Quote::operator=(std::move(item));
		discount = std::move(item.discount);
		quantity = std::move(item.quantity);
	}
#ifdef DEBUG
	std::cout << "Disc_Quote& operator=(Disc_Quote&&)" << std::endl;
#endif
	return *this;
}

Bulk_Quote::Bulk_Quote(const Bulk_Quote& item) :
	Disc_Quote(item) {
#ifdef DEBUG
	std::cout << "Bulk_Quote(const Bulk_Quote&)" << std::endl;
#endif
}

Bulk_Quote::Bulk_Quote(Bulk_Quote&& item) noexcept:
	Disc_Quote(std::move(item)){
#ifdef DEBUG
	std::cout << "Bulk_Quote(Bulk_Quote&&)" << std::endl;
#endif
}

Bulk_Quote::~Bulk_Quote() {
#ifdef DEBUG
	std::cout << "~Bulk_Quote()" << std::endl;
#endif
}

Bulk_Quote&
Bulk_Quote::operator=(const Bulk_Quote& item) {
	if(this!=&item)
		Disc_Quote::operator=(item);
#ifdef DEBUG
	std::cout << "Bulk_Quote& operator=(const Bulk_Quote&)" << std::endl;
#endif
	return *this;
}

Bulk_Quote&
Bulk_Quote::operator=(Bulk_Quote&& item)noexcept {
	if(this!=&item)
		Disc_Quote::operator=(std::move(item));
#ifdef DEBUG
	std::cout << "Bulk_Quote& operator=(Bulk_Quote&&)" << std::endl;
#endif
	return *this;
}

/*-----------------------非成员函数------------------------*/

double print_total(const Quote& item, std::size_t n) {
	auto sum = item.net_price(n);
	std::cout << "bookNo: " << item.isbn()
		<< "\nnet_price: " << sum << std::endl;
	return sum;
}