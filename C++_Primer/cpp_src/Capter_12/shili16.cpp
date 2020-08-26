#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<unordered_map>
#include<memory>
#include<sstream>
#include"StrBlob.h"
using namespace::std;

class QueryResult;

class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream& is);

	QueryResult query(const string& str) const;

private:
	StrBlob file;
	unordered_map<string, shared_ptr<set<line_no>>> word_lines;
};

class QueryResult {
	friend ostream& operator<<(ostream& os, const QueryResult& item);
public:
	using line_no = vector<string>::size_type;
	QueryResult(const string&str, const StrBlob&src_file,const shared_ptr<set<line_no>>&wl):
		word(str),file(src_file),lines(wl){}

private:
	string word;
	StrBlob file;
	shared_ptr<set<line_no>> lines;
};

int main(void)
{
	ifstream infile("infile.txt", ifstream::in);
	TextQuery text(infile);
	string word;
	do {
		cout << "Enter a word to query(quit to quit):";
		if (!(cin >> word) || word == "quit")
			break;
		cout << text.query(word) << endl;
	} while (true);

	return 0;
}

TextQuery::TextQuery(ifstream& is)
{
	line_no cnt = 0;
	for (string line; getline(is, line); ++cnt)
	{
		file.push_back(line);
		istringstream line_stream(line);
		for (string word; line_stream >> word;){
			auto& setl = word_lines[word];
			if (!setl)
				setl.reset(new set<line_no>());
			setl->insert(cnt);
		}
	}
}

QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<set<line_no>> nullsetp(new set<line_no>());
	auto iter = word_lines.find(str);
	if (iter != word_lines.end())
		return QueryResult(str, file, iter->second);
	else
		return QueryResult(str, file, nullsetp);
}

ostream& operator<<(ostream& os, const QueryResult& item)
{
	os << item.word << " occurs " << item.lines->size() << " time(s):" << endl;
	for (const auto& elem : *item.lines)
		os << "\t|__line(" << elem + 1 << ")  " << *(item.file.cbegin() + elem) << endl;
	return os;
}
