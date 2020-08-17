#include<list>
#include<iostream>
#include<algorithm>
using namespace::std;

int main(void)
{
	list<int> ilist{ 1,2,3,4,5,6,4,2,34,4,5,6 };
	list<int> ilist2{ 1,2,3,4,54,23,1 };

	ilist.sort();
	ilist.unique();
	for_each(ilist.begin(), ilist.end(), [](int value) {cout << value << ' '; });
	cout << endl;

	/*ilist.splice(ilist.begin(), ilist2);
	for (auto i : ilist)cout << i << ' '; cout << endl;*/
	ilist.splice(ilist.begin(), ilist2, ilist2.begin());
	ilist.splice(ilist.begin(), ilist2, ilist2.begin(), ilist2.end());
	for (auto i : ilist)cout << i << ' '; cout << endl;

	return 0;
}
