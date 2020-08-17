#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	ifstream infile("phonenum.txt");
	string line;
	regex re("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	while (getline(infile, line)) {
		smatch result;
		if (regex_search(line, result, re))
			cout << result.prefix() <<"phonenumber is:  "<< result.format("$2.$5.$7") << endl;
	}
	infile.close();
	return 0;
}
