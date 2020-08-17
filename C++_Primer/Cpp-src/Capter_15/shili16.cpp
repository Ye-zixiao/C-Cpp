#include<iostream>
#include<vector>
#include<memory>
#include"Quote.h"
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<Quote> qvec;
	int sum = 0;

	qvec.push_back(Quote("show me the world", 23.4));
	qvec.push_back(Bulk_Quote("Operating System", 23.2, 100, 0.25));
	qvec.push_back(Bulk_Quote("Do Something", 33.2, 200, 0.20));
	for_each(qvec.cbegin(), qvec.cend(), [&](const Quote& item) {sum += item.net_price(150); });
	cout << "total net price: " << sum << endl;

	return 0;
}


//result:
//total net price: 11970
