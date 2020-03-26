#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<set>
#include<map>
using namespace::std;

class QueryResult;

class TextQuery {
	friend class QueryResult;
public:
	using line = string;
	using key_type = string;
	using line_num = set<size_t>;
	using key_line_map = map<key_type, line_num>;
	using map_value_type = key_line_map::value_type;

	using map_iterator = key_line_map::iterator;
	using map_citerator = key_line_map::const_iterator;

	TextQuery():
		text_ptr(make_shared<vector<line>>()),pword_line(make_shared<key_line_map>()){}
	TextQuery(ifstream& is,const string&fl) :
		text_ptr(make_shared<vector<line>>()), pword_line(make_shared<key_line_map>()),filename(fl){
		input(is);
	}

	TextQuery& clear(void) {
		if(text_ptr)
			text_ptr->clear();
		if(pword_line)
			pword_line->clear();
		filename.clear();
		return *this;
	}
	TextQuery& reset(ifstream& is,const string&fl) {
		clear();
		input(is);
		filename = fl;
		return *this;
	}
	QueryResult query(const string& s);
	void test(void) const {
		cout << "test text:" << endl;
		for (const auto& elem : *text_ptr)
			cout << "\t" << elem << endl;
		cout << "test map:" << endl;
		for (const auto& elem : *pword_line)
		{
			cout << elem.first << ":";
			for (const auto& ele : elem.second)
				cout << ele << ' ';
			cout << endl;
		}
	}

private:
	void input(ifstream& is);
	shared_ptr<vector<line>> text_ptr;
	shared_ptr<key_line_map> pword_line;
	string filename;
};

void TextQuery::input(ifstream& is)
{
	size_t cnt = 0;
	for (string line; getline(is, line); ++cnt)
	{
		text_ptr->push_back(line);
		string word;
		istringstream line_word(line);
		while (line_word >> word)
			if (pword_line->find(word) == pword_line->end())
				pword_line->insert({ word,set<size_t>{cnt} });
			else
				pword_line->at(word).insert(cnt);
	}
	//test();
}

class QueryResult {
	friend ostream& operator<<(ostream& os, const QueryResult& item);
public:
	using line = string;
	using key_type = string;
	using line_num = set<size_t>;
	using key_line_map = map<key_type, line_num>;
	using map_value_type = key_line_map::value_type;

	using map_iterator = key_line_map::iterator;
	using map_citerator = key_line_map::const_iterator;

	QueryResult() = default;
	QueryResult(map_citerator map_value_iter, shared_ptr<vector<line>> text_p,const string&fl) :
		text_ptr(text_p), word_line_ptr(map_value_iter),filename(fl) {}

private:
	bool expired(void)const {
		if (!text_ptr)
			return true;
		else
			return false;
	}
	shared_ptr<vector<line>> text_ptr;
	map_citerator word_line_ptr;
	string filename;
};

QueryResult TextQuery::query(const string& s)
{
	auto iter = this->pword_line->find(s);
	if (iter != pword_line->end())
		return QueryResult(iter, text_ptr,filename);
	else
	{
		cerr << "Not found" << endl;
		return QueryResult();
	}
}

ostream& operator<<(ostream& os, const QueryResult& item)
{
	if (item.expired())
		return os;
	os << item.word_line_ptr->first << " occurs " << item.word_line_ptr->second.size()
		<< " times:" << endl;
	for (const auto& elem : item.word_line_ptr->second)
		os << "\t|__line " << elem + 1 << ": " << item.text_ptr->at(elem) << endl;
	os << "\t\tfilename: " << item.filename << endl;
	return os;
}

ifstream& openfile(ifstream& is,const string&filename)
{
	is.close();
	is.open(filename, ifstream::in);
	if (!is)
		throw runtime_error("Can't open this file");
	return is;
}

int main(void)
{
	ifstream infile;
	TextQuery file_database;
	while (true) {
		string word;
		cout << "Enter the word your want to search('quit' to quit) $:";
		cin >> word;
		if (word == "quit")
			break;
		if (word[0] == '\\') {
			openfile(infile, word.substr(1));
			file_database.reset(infile, word.substr(1));
			continue;
		}
		if (word[0] != '/')
			continue;
		cout << file_database.query(word.substr(1));
	}
	cout << "----->quit<-----" << endl;

	return 0;
}
