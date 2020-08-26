#include<iostream>
#include<fstream>
#include<string>
using namespace::std;

void check_iostate(istream&is)
{
	if (is.bad())
		cout << "badb" << ' ';
	if (is.fail())
		cout << "fail" << ' ';
	if (is.eof())
		cout << "eof" << ' ';
	if (is.good())
		cout << "good" << ' ';
}

/*clear函数当带有参数的时候，其作用就是将给定的状态（一个或多个状态位，
多个的话用与或非自己组合）建立起来，清楚其他的状态位*/

int main(void)
{
	int value;

	cin.setstate(~cin.badbit | ~cin.failbit | ~cin.eofbit);
	check_iostate(cin);
	cout << endl;
	istream::iostate old_state = cin.rdstate();


	//检查clear的用法
	//cout << (cin.rdstate() & ~cin.failbit & ~cin.badbit) << endl;
	cin.clear(istream::eofbit);//set eofbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::badbit);//set badbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::failbit);//set failbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::eofbit | istream::failbit);//set failbit and eofbit,clear other bits
	check_iostate(cin);
	cout << endl;

	return 0;
}
