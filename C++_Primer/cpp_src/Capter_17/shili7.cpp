#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	regex r("[[:alnum:]]*+\\.(cpp|cxx|cc)$", regex::icase);
	string filename;
	smatch results;
	while (cin >> filename)
		if (regex_search(filename, results, r))
			cout << results.str() << endl;

	return 0;
}
