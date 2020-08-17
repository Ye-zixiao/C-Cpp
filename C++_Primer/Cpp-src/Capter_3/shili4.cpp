#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
	string str;
	if (getline(cin, str))
	{
		decltype(str.size()) punct_cnt = 0;
		for (auto c : str)
			if (ispunct(c))
				++punct_cnt;

		cout << punct_cnt << " punctuation character(s) in string \"" << str << "\"." << endl;
		return 0;
	}
	else
	{
		cerr << "No data!" << endl;
		return -1;
	}
}
