#include<iostream>
#include<fstream>
#include<string>
using namespace::std;

istream& func(istream& is)
{
	char ch;
	while (is >> ch, !is.eof())
		cout << ch;
	is.clear();
	return is;
}

int main(void)
{
	func(cin);

	return 0;
}
