#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<set>
#include<memory>
using namespace::std;

class QueryResult;

class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&is):
		file(new vector<string>()) {
		input(is);
	}
	QueryResult query(const string& str) const;

private:
	void input(ifstream& is);
	shared_ptr<vector<string>> file;
	unordered_map<string, shared_ptr<set<line_no>>> word_lines;
};


void TextQuery::input(ifstream& is)
{
	line_no cnt = 0;
	for (string line; getline(is, line); ++cnt)
	{
		file->push_back(line);
		istringstream line_stream(line);
		for (string word; line_stream >> word;) {
			auto& ps = word_lines[word];
			if (!ps)
				ps.reset(new set<line_no>());
			ps->insert(cnt);
		}
	}
}

class QueryResult {
	friend ostream& operator<<(ostream& os, const QueryResult& item);
public:
	using line_no = vector<string>::size_type;
	QueryResult(const string&str,const shared_ptr<vector<string>>&src_file,const shared_ptr<set<line_no>>&ls):
		lines(ls),file(src_file),word(str){}

private:
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
	string word;
};


QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<set<line_no>> nulllines(new set<line_no>);
	auto iter = word_lines.find(str);
	if (iter != word_lines.end())
		return QueryResult(str, file, iter->second);
	else
		return QueryResult(str, file, nulllines);

}


ostream& operator<<(ostream& os, const QueryResult& item)
{
	os << item.word << " occurs " << item.lines->size() << " time(s):" << endl;
	for (const auto& ln : *item.lines)//不能对空的智能指针解引用
		os << "\t|____(line " << ln + 1 << ") " << (*item.file)[ln] << endl;
	return os;
}

int main(void)
{
	ifstream infile("infile.txt", ifstream::in);

	TextQuery text(infile);
	while (true) {
		string word;
		cout << "Enter a word to search(q to quit):";
		if(!(cin >> word) || word=="quit")
			break;
		cout << text.query(word) << endl;
	}

	return 0;
}
