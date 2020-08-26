#include<iostream>
#include<vector>
#include<memory>
#include"Quote.h"
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<shared_ptr<Quote>> qvec;
	double sum = 0.0;

	qvec.push_back(make_shared<Quote>("hello world", 23.4));
	qvec.push_back(make_shared<Bulk_Quote>("Operating System", 23.2, 100, 0.25));
	qvec.push_back(make_shared<Bulk_Quote>("Data Structrue", 33.2, 200, 0.20));
	for_each(qvec.begin(), qvec.end(), [&](const shared_ptr<Quote>& p) {sum += p->net_price(120); });
	cout << "total net price: " << sum << endl;

	return 0;
}

//result:
//total net price: 8880
