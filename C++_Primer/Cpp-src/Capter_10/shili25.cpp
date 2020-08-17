#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
using namespace::std;

int main(void)
{
	ifstream in_file("in_file.txt", ::ifstream::in);
	if (!in_file)
	{
		cerr << "can't open this file" << endl;
		return -1;
	}

	istream_iterator<string> in_iter(in_file), eof;
	ostream_iterator<string> out(cout," ");
	vector<string> strvec(in_iter, eof);
	for (auto str : strvec)out=str; cout << endl;//这里可以使用for_each函数

	return 0;
}
