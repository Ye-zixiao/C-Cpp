#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<list>
using namespace::std;

void print(const deque<int>& ideq)
{
	for (const auto& i : ideq)
		cout << i << ' ';
	cout << endl;
}

int main(void)
{
	list<int> ilist;
	deque<int> even,odd;
	for (size_t i = 0; i != 10; ++i)
		ilist.push_back(i);

	/*for (const auto& elem : ilist)
		if (elem % 2 == 0)
			ideq1.push_back(elem);
		else
			ideq2.push_back(elem);*///对于if-else这样的语句尽量写成如下的形式：
    for(const auto&elem:ilist)
        (elem%2==0?even:odd).push_back(elem);


	print(even);
	print(odd);

	return 0;
}
