#ifndef _TUPLE_TEXTQUERY_H_
#define _TUPLE_TEXTQUERY_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<tuple>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>

class tupleTextQuery {
public:
	using size_type = std::vector<std::string>::size_type;
	using lines_set = std::set<size_type>;
	using lines_set_sp = std::shared_ptr<lines_set>;
	using text = std::vector<std::string>;
	using text_sp = std::shared_ptr<text>;
	using Query_Result = std::tuple<std::string, text_sp, lines_set_sp>;

	tupleTextQuery(std::ifstream& ifs) {
		input(ifs);
	}

	Query_Result query(const std::string& str);

private:
	void input(std::ifstream&ifs);
	std::shared_ptr<std::vector<std::string>> ptext;
	std::unordered_map<std::string, std::shared_ptr<lines_set>> word_lines;
};


tupleTextQuery::Query_Result
tupleTestQuery::input(std::ifstream&ifs){
    size_type cnt=0;
    for(std::string line;getline(ifs,line);++cnt){
        ptext->push_back(line);
        std::istringstream istring(line);
        for(std::string word;istrin>>word;){
            auto& ret=word_lines[word];
            if(!ret)
                ret.reset(new lines_set());
            ret->insert(cnt);
        }
    }
}

tupleTestQuery::Query_Result
tupleTestQuery::query(const std::string&str){
    static std::shared_ptr<lines_set> nullsetp();
    auto ret=word_lines.find(str);
    if(ret!=word_lines.end())
        return Query_Result{str,ptext,ret};
    else
        return Query_Result{str,ptext,nullsetp};
}

#endif
