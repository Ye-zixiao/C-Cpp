#include<iostream>
#include"Quote.h"
#include<memory>
using namespace::std;

int main(void)
{
	shared_ptr<Quote> sp(new Bulk_Quote());
	shared_ptr<Quote> sp_cpy(make_shared<Bulk_Quote>());
	//Quote item = Bulk_Quote;//��Ϊitem�Ȳ�������Ҳ����ָ�룬�������Ķ�̬������Զ�Ǿ�̬����
	Bulk_Quote bulk;
	Quote item(bulk);
	item = bulk;
}