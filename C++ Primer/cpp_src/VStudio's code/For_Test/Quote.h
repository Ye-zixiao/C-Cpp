#ifndef  _QUOTE_H_
#define _QUOTE_H_

#include<iostream>
#include<utility>
#include"String.h"

class Quote {
public:
	Quote() = default;
	Quote(const String&book,double p):
		bookNo(book),price(p){}
	Quote(const Quote& item);
	Quote(Quote&& item)noexcept;
	virtual ~Quote();

	Quote& operator=(const Quote& item);
	Quote& operator=(Quote&& item)noexcept;

	String isbn(void) const;
	virtual double net_price(std::size_t n) const;
	virtual Quote* clone(void) const& { return new Quote(*this); }
	virtual Quote* clone(void)&& { return new Quote(std::move(*this)); }

private:
	String bookNo;
protected:
	double price = 0.0;
};


class Disc_Quote :public Quote {
public:
	Disc_Quote() = default;
	Disc_Quote(const String&book,double price,std::size_t n,double disc):
		Quote(book,price),quantity(n),discount(disc){}
	Disc_Quote(const Disc_Quote& item);
	Disc_Quote(Disc_Quote&& item)noexcept;
	~Disc_Quote() override;

	Disc_Quote& operator=(const Disc_Quote& item);
	Disc_Quote& operator=(Disc_Quote&& item)noexcept;

	double net_price(std::size_t n) const = 0;//纯虚函数声明

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};


class Bulk_Quote :public Disc_Quote {
public:
	using Disc_Quote::Disc_Quote;

	Bulk_Quote() = default;
	Bulk_Quote(const Bulk_Quote& item);
	Bulk_Quote(Bulk_Quote&& item)noexcept;
	~Bulk_Quote() override;

	Bulk_Quote& operator=(const Bulk_Quote& item);
	Bulk_Quote& operator=(Bulk_Quote&& item) noexcept;

	double net_price(std::size_t n) const override;
	Bulk_Quote* clone(void) const& override { return new Bulk_Quote(*this); }//克隆出来一个新的自己，这个对象是自己的副本
	Bulk_Quote* clone(void)&& override { return new Bulk_Quote(std::move(*this)); }//克隆出来一个新的自己，这个对象通过移动构造函数接管了自己曾经管理的动态内存
};

class Mulk_Quote :public Disc_Quote {
public:
	Mulk_Quote() = default;
	Mulk_Quote(const String&book,double price,std::size_t quan,double disc):
		Disc_Quote(book,price,quan,disc){}

	double net_price(std::size_t n) const override;
};

extern double print_total(const Quote&, std::size_t);

#endif //  _QUOTE_H_
