#include<iostream>
#include<cctype>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace::std;

string& str_dispose(string& str)
{
	for (auto& ch : str)
		ch = tolower(ch);
	auto erase_iter = remove_if(str.begin(), str.end(),[](const char&ch){return ch==',';});
	//���������ʹ��ispunct���������������VS��û��ʲô����
	str.erase(erase_iter, str.end());
	//��ס�������㷨�����ڵ�����֮�ϣ�����ִ������������������Ҳ����ı������Ĵ�С����ôɾ��һЩԪ�صĹ�����Ȼ���ǲ���ɵ�

	return str;
}

int main(void)
{
	string word;
	map<string, size_t> word_count;
	set<string> excluded{
		"an","a","the","and","is","are"
	};

	while (cin >> word)
		if (!word.empty() && excluded.find(str_dispose(word)) == excluded.end())
			++word_count[word];
	for (const auto& elem : word_count)
		cout << "\t" << elem.first << " occurs " << elem.second << endl;

	return 0;
}
