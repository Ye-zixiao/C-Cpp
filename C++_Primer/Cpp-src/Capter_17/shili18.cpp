#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	string str("freind theif friend");
	string re("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	smatch result;
	for (sregex_iterator iter(str.begin(), str.end(), re), end_iter;
		iter != end_iter; ++iter)
		cout << iter->str() << endl;

	return 0;
}
