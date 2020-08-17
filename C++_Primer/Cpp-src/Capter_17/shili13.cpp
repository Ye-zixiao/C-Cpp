#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	smatch result;
	string str;
	regex re("(.+)\\.(cpp|cc|cxx)$", regex::icase);
	while (cin >> str) {
		if (regex_search(str, result, re))
			cout << result.str(0) << ' ' << result.str(1) << ' ' << result.str(2) << endl;
	}
	return 0;
}
