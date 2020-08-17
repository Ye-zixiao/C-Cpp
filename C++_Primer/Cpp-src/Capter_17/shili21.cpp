#include<iostream>
#include<regex>
#include<string>
#include<sstream>
using namespace::std;
using namespace std::regex_constants;

int main(void)
{
	ostringstream oss;
	regex re("(\\d{5})([-. ])?(\\d{4})");
	string line;
	while (getline(cin, line)) {
		string temp = regex_replace(line, re, string("$1-$3 "),format_no_copy);
		if (!temp.empty())
			oss << temp << '\n';
	}
	cout << "Replace results:" << endl
		<< oss.str() << endl;

	return 0;
}
