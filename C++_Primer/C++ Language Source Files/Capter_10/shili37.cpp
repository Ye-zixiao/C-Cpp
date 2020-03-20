#include<iostream>
#include<forward_list>
using namespace::std;

ostream& operator<<(ostream& os, const forward_list<int>& flist)
{
	for (const auto& i : flist)os << i << ' '; return os;
}

int main(void)
{
	forward_list<int> flist{ 1,3,43,5,6,3,3 };
	forward_list<int> flist_move{ 3,2,14,3,2,4,3 };

	flist.sort(); flist_move.sort();
	flist.unique(); flist_move.unique();
	cout << flist << '\n' << flist_move << endl;
	flist.splice_after(flist.before_begin(), flist_move, flist_move.begin());
	cout << flist << endl;
	flist.splice_after(flist.before_begin(), flist_move, flist_move.before_begin(), flist_move.end());
	for (auto i : flist)cout << i << ' '; cout << endl;

	return 0;
}
