#include<iostream>
#include<set>
#include<memory>
#include<algorithm>
#include"Quote.h"
using namespace::std;

class Basket {
public:
	void add_item(const shared_ptr<Quote>& sale);
	void add_item(const Quote& sale);
	void add_item(Quote&& sale);

	double total_receipt(void)const;

private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs);
	multiset<shared_ptr<Quote>, decltype(compare)*> item{ compare };
};

double Basket::total_receipt(void)const {
	double sum = 0.0;
	//在这个for语句中迭代器的递增方式并不是通过递增运算符，而是通过upper_bound成员函数将迭代器直接指向到下一个不同关键字的元素上
	for (auto iter = item.cbegin(); iter != item.cend(); iter = item.upper_bound(*iter))
		//sum += print_total(**iter, item.count(*iter));
		sum += print_total(**iter, 120);
	cout << "Total sale: " << sum << endl;
	return sum;
}

void Basket::add_item(const shared_ptr<Quote>& sale) {
	item.insert(sale);
}

void Basket::add_item(const Quote& sale) {
	item.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote&& sale) {
	item.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

bool Basket::compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {
	return lhs->isbn() < rhs->isbn();
}

int main(void)
{
	Basket lanzi;
	lanzi.add_item(Quote("show me the world", 23.4));
	lanzi.add_item(Bulk_Quote("Operating System", 23.2, 100, 0.25));
	lanzi.add_item(Bulk_Quote("Do Something", 33.2, 200, 0.20));
	lanzi.total_receipt();

	return 0;
}
