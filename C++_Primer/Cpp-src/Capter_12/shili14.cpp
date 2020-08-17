#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<sstream>
#include<map>
#include<set>
using namespace::std;

void input(ifstream& is, vector<string>& store, map<string, set<size_t>>& line_db)
{
	size_t cnt = 0;
	string line;
	for (; getline(is, line); ++cnt)
	{
		store.push_back(line);
		string word;
		istringstream line2word(line);
		/*while (line2word >> word) {
			auto iter = line_db.find(word);
			if (iter == line_db.end())
				line_db.insert({ word,set<size_t>{cnt} });
			else
				iter->second.insert(cnt);
		}*/
		while(line2word>>word)
            line_db[word].insert(cnt);
        //上面一大堆不如这样用简单，同时word还可以使用像remove_copy_if这样的泛型算法来处理单词
	}
}

ostream& search(const string&str,const vector<string>& store, map<string, set<size_t>>& line_db,ostream&os=cout)
{
	auto iter = line_db.find(str);
	if (iter != line_db.end()) {
		os << str << " occurs " << iter->second.size() << " times:" << endl;
		for (const auto& elem : iter->second)
			os << "\t|___line(" << elem+1 << ")  " << store[elem] << endl;
	}
	else cerr << "Not found" << endl;
	return os;
}

int main(void)
{
	vector<string> text;
	map<string, set<size_t>> line_db;
	ifstream infile("infile.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	input(infile, text, line_db);
	string word;
	do {
		cout << "Enter the word your want to search('quit' to quit) $:";
		cin >> word;
		if (word[0] == '/') {
			search(word.substr(1), text, line_db);
		}
	} while (word != "quit");
	cout << "----->quit<-----" << endl;

	return 0;
}
