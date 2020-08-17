#include<iostream>
#include<sstream>
#include<string>
using namespace::std;

istream& print(istream& is)
{
	string temp;
	while (is>>temp)
		cout << temp << ' ';
	is.clear();
	return is;
}

int main(void)
{
	const string str = "hello world,hello china!";
	istringstream in(str);
	print(in);
	cout << endl;

	return 0;
}
