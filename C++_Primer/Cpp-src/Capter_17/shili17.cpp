#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	ifstream infile("phonenum.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	string line;
	string fmt("($2) $5-$7");
	regex re("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	while (getline(infile, line))
		cout << regex_replace(line, re, fmt) << endl;
	infile.close();
	return 0;
}
