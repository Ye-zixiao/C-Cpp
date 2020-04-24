#include<iostream>
#include"Quote.h"
#include<memory>
using namespace::std;

int main(void)
{
	shared_ptr<Quote> sp(new Bulk_Quote());
	shared_ptr<Quote> sp_cpy(make_shared<Bulk_Quote>());
	//Quote item = Bulk_Quote;//因为item既不是引用也不是指针，所以它的动态类型永远是静态类型
	Bulk_Quote bulk;
	Quote item(bulk);
	item = bulk;
}