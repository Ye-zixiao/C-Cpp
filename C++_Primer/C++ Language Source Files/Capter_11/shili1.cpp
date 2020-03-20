#include<iostream>
#include<map>
#include<set>
#include<string>
#include<cctype>
#define NDEBUG
using namespace::std;

string& str_dispose(string& str)
{
#ifndef NDEBUG
	cout << str << endl;
#endif
	const string dots(",.?!");
	string::size_type pos = 0;
	while ((pos = str.find_first_of(dots, pos)) != string::npos)
		str.erase(pos, 1);
	for (auto & ch:str)
		ch = tolower(ch);
#ifndef NDEBUG
	cout << str << endl;
#endif
	return str;
}


int main(void)
{
	map<string, size_t> word_count;
	set<string> excluded{
		"the","a","an","and","however","but","is","are"
	};
	string word;
	while (cin >> word)
		if (!word.empty() && excluded.find(str_dispose(word)) == excluded.end())
			++word_count[word];

	for (const auto& elem : word_count)
		cout << elem.first << " occurs " << elem.second << endl;

	return 0;
}
