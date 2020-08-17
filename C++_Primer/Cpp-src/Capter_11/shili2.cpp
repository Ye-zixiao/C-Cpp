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
	//这里好像不能使用ispunct这个函数，不过在VS上没有什么问题
	str.erase(erase_iter, str.end());
	//记住：泛型算法作用于迭代器之上，而不执行容器操作，所以他也不会改变容器的大小，那么删除一些元素的工作显然它是不会干的

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
