#ifndef _REMOULD_TEXTQUERY_H_
#define _REMOULD_TEXTQUERY_H_

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<memory>
#include<set>

namespace remould {

	class TextQuery {
	public:
		using size_type = std::vector<std::string>::size_type;
		using line_nos = std::set<size_type>;
		class QueryResult;//嵌套类

		TextQuery(std::ifstream& ifs);
		QueryResult query(const std::string& str) const;
		size_type line_size(void) const;

	private:
		void input(std::ifstream& ifs);
		std::shared_ptr<std::vector<std::string>> sp_text;
		std::unordered_map<std::string, std::shared_ptr<line_nos>> word_line_nos;
	};

	class TextQuery::QueryResult {
		friend std::ostream& operator<<(std::ostream& os, const QueryResult& result);
	public:
		QueryResult(const std::string& s, const std::shared_ptr<std::vector<std::string>>& sp,
			const std::shared_ptr<line_nos>& nos_sp) :
			word(s), sp_text(sp), line_nos(nos_sp) {}

	private:
		std::string word;
		std::shared_ptr<std::vector<std::string>> sp_text;
		std::shared_ptr<line_nos> line_nos;
	};

	/*
	 *Other function defination,includes:
		1.TextQuery--Constructor
		2.TextQuery--input
		3.TextQuery--query
		4.operator<<--QueryResult
	 */
	TextQuery::TextQuery(std::ifstream& ifs) :
		sp_text(new std::vector<std::string>()) {
		input(ifs);
	}

	void TextQuery::input(std::ifstream& ifs) {
		size_type cnt = 0;
		for (std::string line; getline(ifs, line); ++cnt) {
			sp_text->push_back(line);
			std::istringstream line_stream(line);
			for (std::string word; line_stream >> word;) {
				/*因为一开始的时候word_line_nos关键字所对应的值mapped_value是一个空的共享指针，
					所以需要用reset成员函数重置下共享指针*/
				auto& ret_sp = word_line_nos[word];
				if (!ret_sp)
					ret_sp.reset(new line_nos());
				ret_sp->insert(cnt);
			}
		}
	}

	TextQuery::QueryResult TextQuery::query(const std::string& str)const {
		static std::shared_ptr<line_nos> nodata(new line_nos());
		auto ret = word_line_nos.find(str);
		if (ret != word_line_nos.end())
			return QueryResult(str, sp_text, ret->second);
		else
			return QueryResult(str, sp_text, nodata);
	}

	std::ostream& operator<<(std::ostream& os, const TextQuery::QueryResult& result) {
		os << "Word (" << result.word << ") occurs " << result.line_nos->size() 
			<< " times:" << std::endl;
		for (const auto& elem : *result.line_nos)
			os << "\t|__line(" << elem + 1 << "): " << (*result.sp_text)[elem]
				<< std::endl;
		return os;
	}

	TextQuery::size_type TextQuery::line_size(void) const {
		return sp_text ? sp_text->size() : 0;
	}
}


#endif