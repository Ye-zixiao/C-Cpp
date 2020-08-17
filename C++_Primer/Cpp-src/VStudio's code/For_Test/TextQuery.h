#ifndef	_TEXTQUERY_H_
#define _TEXTQUERY_H_

#include<unordered_map>
#include<string>
#include<vector>
#include<memory>
#include<set>
#include<fstream>
#include<sstream>
#include"DebugDelete.h"

class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	using lines = std::set<line_no>;
	TextQuery(std::ifstream& is) :
		pfile(new std::vector<std::string>(),DebugDelete()) {
		input(is);
	}

	QueryResult query(const std::string& str) const;

private:
	void input(std::ifstream& is);
	std::shared_ptr<std::vector<std::string>> pfile;					//记录输入文件的每一行
	std::unordered_map<std::string, std::shared_ptr<lines>> word_lines;	//记录每一个单词所出现的行号
};


class QueryResult {
	friend std::ostream& operator<<(std::ostream& os, const QueryResult& item);
public:
	using line_no = std::vector<std::string>::size_type;
	using lines = std::set<line_no>;

	QueryResult(const std::string&str,std::shared_ptr<std::vector<std::string>> psrc_file,std::shared_ptr<lines> psrc_line_set):
		pline_set(psrc_line_set),pfile(psrc_file),word(str){}

	std::shared_ptr<std::vector<std::string>> get_file(void) const {
		return pfile;
	}

	lines::iterator begin(void) {
		return pline_set->begin();
	}
	lines::iterator end(void) {
		return pline_set->end();
	}

private:
	std::shared_ptr<std::vector<std::string>> pfile;
	std::shared_ptr<lines> pline_set;
	std::string word;
};

#endif