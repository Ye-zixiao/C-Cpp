#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
	try {
		regex r("[[:alnum:]]*+\\.(cpp|cxx|cc)$", regex::icase);//���������ʽ���д���ģ�һ������������ʽ�д���ͻ��׳�һ��regex_err�쳣
		//regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
		//regex r(".+\\.(cpp|cc|cxx)$", regex::icase);
		string filename;
		smatch results;//����ʹ��smatch����Ϊ����������string������const char*
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
