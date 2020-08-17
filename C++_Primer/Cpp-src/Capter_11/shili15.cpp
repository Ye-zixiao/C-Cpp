#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<set>
using namespace::std;

int main(void)
{
	const set<string> cstrset{
		"a","the","an","and","but","is","are"
	};
	map<string, size_t> word_count;
	string word;

	while (cin >> word)
		if (cstrset.find(word) == cstrset.end())
		{
			auto ret_pair = word_count.insert({ word,1 });
			//insert�������ֳ�����Ĳ�������ʹ���±겢�������ֳ�����Ĳ���
			if (!ret_pair.second)
				++ret_pair.first->second;
		}

	for (auto iter = word_count.begin(); iter != word_count.end(); ++iter)
		cout << iter->first << ' ' << iter->second << endl;
	return 0;
}
