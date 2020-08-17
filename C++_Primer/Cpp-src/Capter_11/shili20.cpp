#include<iostream>
#include<string>
#include<cctype>
#include<unordered_map>
#include<unordered_set>
using namespace::std;

string Tolower(string& str)
{
	for (auto& ch : str)
		ch = tolower(ch);
	return str;
}

int main(void)
{
	unordered_map<string, size_t> word_count;
	unordered_set<string> excluded = {
		"the","an","a","it't","is","are","his","her","your","my"
	};
	string word;
	while (cin >> word)
		if(excluded.find(Tolower(word))==excluded.end())
			++word_count[word];
	for (const auto& word_elem : word_count)
		cout << word_elem.first << ' ' << word_elem.second << endl;

	return 0;
}
