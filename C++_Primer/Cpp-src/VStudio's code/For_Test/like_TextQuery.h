#ifndef LIKE_TEXTQUERY_H_INCLUDED
#define LIKE_TEXTQUERY_H_INCLUDED

#include"StrVec.h"
#include<unordered_map>
#include<set>
#include<fstream>
#include<iostream>
#include<sstream>

/*��Ȼ��ͬһ����Ŀ�в�ͬ���ඨ���ڲ�ͬ��ͷ�ļ��У�����ʹ��ˣ�Ҳ��Ҫ��ͬһ���ļ���
*��������ӵ����ͬ���ֵ��࣬��ᵼ�±�������ʾ�����������ض������
*/
class like_QueryResult;

class like_TextQuery {
public:
    using line_no = StrVec::size_type;
    using lines = std::set<line_no>;

    like_TextQuery(std::ifstream& is) :
        pfile(new StrVec) {
        input(is);
    }

    like_QueryResult query(const std::string& str);

private:
    void input(std::ifstream& is);
    std::shared_ptr<StrVec> pfile;
    std::unordered_map<std::string, std::shared_ptr<lines>> pword_lines;
};


class like_QueryResult {
    friend std::ostream& operator<<(std::ostream& os, const like_QueryResult& item);
public:
    using line_no = StrVec::size_type;
    using lines = std::set<line_no>;
    like_QueryResult(const std::string& str, std::shared_ptr<StrVec> pf, std::shared_ptr<lines> pl) :
        word(str), pfile(pf), plines(pl) {}

private:
    std::string word;
    std::shared_ptr<StrVec> pfile;
    std::shared_ptr<lines> plines;
};


/*---------------------------������Ա��������----------------------------------------*/

void
like_TextQuery::input(std::ifstream& is) {
    line_no cnt = 0;
    for (std::string line; getline(is, line); ++cnt) {
        pfile->push_back(line);
        std::istringstream line_stream(line);
        for (std::string word; line_stream >> word;) {
            auto& ret = pword_lines[word];
            if (!ret)
                //ret.reset(new lines);//Ҫ��һ��shared_ptr����ָ��ָ���µĶ�̬�ڴ棬����ʹ��reset����
                //����Ҫ֪������ָ�룺q.reset(p1)��q=p2����һ���ĵȼ��ԣ���֮ͬ������p1������ָ�룬p2�ǹ���ָ��
                ret = std::make_shared<lines>();
            ret->insert(cnt);
        }
    }
}

like_QueryResult
like_TextQuery::query(const std::string& str) {
    static std::shared_ptr<lines> nullset(new lines);
    auto iter = pword_lines.find(str);
    if (iter != pword_lines.end())
        return like_QueryResult(str, pfile, iter->second);
    else
        return like_QueryResult(str, pfile, nullset);
}

std::ostream& operator<<(std::ostream& os, const like_QueryResult& item) {
    os << item.word << " occurs " << item.plines->size() << " times:" << std::endl;
    for (const auto& elem : *item.plines)
        os << "\t|___lines(" << elem << "): " << (*item.pfile)[elem] << std::endl;
    return os;
}

#endif // LIKE_TEXTQUERY_H_INCLUDED
