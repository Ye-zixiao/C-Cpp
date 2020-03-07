#include<iostream>
#include<forward_list>
#include<list>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
	list<int> ilist{ 1,2,3,4,5,6,7,8,9 };
	for (auto iter = ilist.begin(); iter != ilist.end();)
		if (*iter & 0x1) {
			ilist.insert(iter, *iter);
			++iter;
		}
		else
			iter = ilist.erase(iter);

	for (auto i : ilist)cout << i << ' '; cout << endl;

	return 0;
}
