#include<iostream>
#include<vector>
#include"Sales_data.h"
#include<functional>
#include<algorithm>
using namespace::std;
using namespace::placeholders;

vector<Sales_data>::const_iterator
more_than_avg(const vector<Sales_data>& sdvec, double give) {
	return find_if(sdvec.cbegin(), sdvec.cend(), [&](const Sales_data& item) {
		//return item.avg_price() > give;
		//return mem_fn(&Sales_data::avg_price)(item) > give;
		/*auto f = bind(&Sales_data::avg_price, _1);
		return f(item) > give;*/
		function<double(const Sales_data&)> fcn = &Sales_data::avg_price;
		return fcn(item) > give;
		});
}

int main(void)
{
	vector<Sales_data> sdvec{ Sales_data("1",1,23.2),
		Sales_data("2",1,24.2),Sales_data("34",2,45.2) };
	auto iter = more_than_avg(sdvec, 30.0);
	cout << iter->isbn() << endl;

	return 0;
}
