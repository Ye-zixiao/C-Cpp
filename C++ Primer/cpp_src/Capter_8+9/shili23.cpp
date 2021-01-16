#include<forward_list>
#include<iostream>
using namespace::std;

int main(void)
{
	forward_list<int> flist{ 1,2,3,4,5,6,7,8,9 };
	auto pre = flist.before_begin();
	for (auto iter = flist.begin(); iter != flist.end();)
		if (*iter & 0x1) {
			flist.insert_after(pre, *iter);
			pre = iter;
			++iter;
		}
		else
			iter = flist.erase_after(pre);

	for (auto i : flist)cout << i << ' '; cout << endl;

	return 0;
}
