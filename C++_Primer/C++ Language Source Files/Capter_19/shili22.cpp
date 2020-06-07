#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace::std;

class bookNo_ptr {
public:
	bookNo_ptr(const Sales_data*p):
		psd(p){}

	const string& operator*() const {
		return psd->*pbookNo;
	}
	const string* operator->() const {
		return &this->operator*();
	}

private:
	const string Sales_data::* pbookNo = &Sales_data::bookNo;
	const Sales_data* psd;

};

int main(void)
{
	Sales_data item("Operating System", 23, 33.2);
	bookNo_ptr bnp(&item);
	cout << *bnp << endl;
	cout << bnp->size() << endl;

	return 0;
}
