#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	try {
		regex r("[[:alnum:]]*+\\.(cpp|cxx|cc)$", regex::icase);//这个正则表达式是有错误的，一旦发现正则表达式有错误就会抛出一个regex_err异常
		//regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
		//regex r(".+\\.(cpp|cc|cxx)$", regex::icase);
		string filename;
		smatch results;//必须使用smatch，因为输入序列是string而不是const char*
		//cmatch results;
		while (cin >> filename)
			if (regex_search(filename, results, r))
				cout << results.str() << endl;
	}
	catch (std::regex_error& err) {
		cout << err.what() << endl << err.code() << endl;
	}

	string str("hello world show");
	regex re("(world|show)", regex::egrep);
	smatch results;
	if (regex_search(str, results, re))
		cout << results.str() << endl;

	return 0;
}
