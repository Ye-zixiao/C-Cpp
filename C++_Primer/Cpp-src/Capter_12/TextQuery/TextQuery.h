#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<set>
#include<map>

class QueryResult;

class TextQuery {
	friend class QueryResult;
public:
	using line = std::string;
	using key_type = std::string;
	using line_num = std::set<size_t>;
	using key_line_map = std::map<key_type, line_num>;
	using map_value_type = key_line_map::value_type;

	using map_iterator = key_line_map::iterator;
	using map_citerator = key_line_map::const_iterator;

	TextQuery() :
		text_ptr(std::make_shared<std::vector<line>>()), pword_line(std::make_shared<key_line_map>()) {}
	TextQuery(std::ifstream& is, const std::string& fl) :
		text_ptr(std::make_shared<std::vector<line>>()), pword_line(std::make_shared<key_line_map>()), filename(fl) {
		input(is);
	}

	TextQuery& clear(void) {
		if (text_ptr)
			text_ptr->clear();
		if (pword_line)
			pword_line->clear();
		filename.clear();
		return *this;
	}
	TextQuery& reset(std::ifstream& is, const std::string& fl) {
		clear();
		input(is);
		filename = fl;
		return *this;
	}
	QueryResult query(const std::string& s);
	void test(void) const {
		std::cout << "test text:" << std::endl;
		for (const auto& elem : *text_ptr)
			std::cout << "\t" << elem << std::endl;
		std::cout << "test map:" << std::endl;
		for (const auto& elem : *pword_line)
		{
			std::cout << elem.first << ":";
			for (const auto& ele : elem.second)
				std::cout << ele << ' ';
			std::cout << std::endl;
		}
	}
	const std::vector<std::string>& text(void) const {
		return *text_ptr;
	}
private:
	void input(std::ifstream& is);
	std::shared_ptr<std::vector<line>> text_ptr;
	std::shared_ptr<key_line_map> pword_line;
	std::string filename;
};

void TextQuery::input(std::ifstream& is)
{
	size_t cnt = 0;
	for (std::string line; getline(is, line); ++cnt)
	{
		text_ptr->push_back(line);
		std::string word;
		std::istringstream line_word(line);
		while (line_word >> word)
			if (pword_line->find(word) == pword_line->end())
				pword_line->insert({ word,std::set<size_t>{cnt} });
			else
				pword_line->at(word).insert(cnt);
	}
	//test();
}

class QueryResult {
	friend std::ostream& operator<<(std::ostream& os, const QueryResult& item);
public:
	using line = std::string;
	using key_type = std::string;
	using line_num = std::set<size_t>;
	using key_line_map = std::map<key_type, line_num>;
	using map_value_type = key_line_map::value_type;

	using map_iterator = key_line_map::iterator;
	using map_citerator = key_line_map::const_iterator;

	QueryResult() = default;
	QueryResult(map_citerator map_value_iter, std::shared_ptr<std::vector<line>> text_p, const std::string& fl) :
		text_ptr(text_p), word_line_ptr(map_value_iter), filename(fl) {}

private:
	bool expired(void)const {
		if (!text_ptr)
			return true;
		else
			return false;
	}
	std::shared_ptr<std::vector<line>> text_ptr;
	map_citerator word_line_ptr;
	std::string filename;
};

QueryResult TextQuery::query(const std::string& s)
{
	auto iter = this->pword_line->find(s);
	if (iter != pword_line->end())
		return QueryResult(iter, text_ptr, filename);
	else
	{
		std::cerr << "Not found" << std::endl;
		return QueryResult();
	}
}

std::ostream& operator<<(std::ostream& os, const QueryResult& item)
{
	if (item.expired())
		return os;
	os << item.word_line_ptr->first << " occurs " << item.word_line_ptr->second.size()
		<< " times:" << std::endl;
	for (const auto& elem : item.word_line_ptr->second)
		os << "\t|__line " << elem + 1 << ": " << item.text_ptr->at(elem) << std::endl;
	os << "\t\tfilename: " << item.filename << std::endl;
	return os;
}

std::ifstream& openfile(std::ifstream& is, const std::string& filename)
{
	is.close();
	is.open(filename, std::ifstream::in);
	if (!is)
		throw std::runtime_error("Can't open this file");
	return is;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& item)
{
	os << std::endl;
	for (std::vector<std::string>::size_type i = 0; i < item.size(); ++i)
		os << i + 1 << (i + 1 <= 9 ? " " : "") << ' ' << item[i] << std::endl;
	os << std::endl;
	return os;
}

#endif // !_TEXTQUERY_H_
