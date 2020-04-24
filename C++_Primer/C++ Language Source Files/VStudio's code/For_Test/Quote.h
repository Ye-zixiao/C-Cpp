#ifndef  _QUOTE_H_
#define _QUOTE_H_

#include<iostream>
#include<string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string&book,double book_price)
		:bookNo(book),price(book_price){}
	virtual ~Quote() = default;

	std::string isbn(void) const;
	virtual double net_price(std::size_t n) const;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Bulk_Quote final:public Quote {
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string&book,double price,std::size_t n,double dis):
		Quote(book,price),min_cnt(n),discount(dis){}
	~Bulk_Quote() = default;

	double net_price(std::size_t n) const override;

private:
	std::size_t min_cnt = 0;
	double discount = 0.0;
};

extern void print_total(std::ostream&, const Quote&, std::size_t);

#endif //  _QUOTE_H_
