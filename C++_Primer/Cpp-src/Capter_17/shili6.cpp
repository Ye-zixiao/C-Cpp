#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	regex r(pattern);
	smatch results;
	string test_str("receipt freind theif receive");
	if (regex_search(test_str, results, r))
		cout << results.str() << endl;

	return 0;
}
