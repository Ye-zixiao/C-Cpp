#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>
#include"Sales_data.h"//这个就不运行了
using namespace::std;

template<typename Type>
ostream& operator<<(ostream& os, const vector<Type>& item)
{
	for (const auto& elem : item)
		os << elem << endl;
	return os;
}

int main(void)
{
	istream_iterator<Sales_data> in_iter(cin), eof;
	vector<Sales_data> svec(in_iter, eof);

	sort(svec.begin(), svec.end(), isShorter_Isbn);
	//cout << svec << endl;
	for (auto beg = svec.begin(), end = beg; beg != svec.end(); beg = end)
	{
		end = find_if(beg, svec.end(), [beg](const Sales_data& item) {return item.isbn() != beg->isbn(); });
		cout << accumulate(beg, end, Sales_data(beg->isbn())) << endl;
	}

	return 0;
}
