#include"TextQuery.h"

/*
*TextQuery类的成员函数
*
*/

void TextQuery::input(std::ifstream& is)
{
	line_no cnt = 0;
	for (std::string line; getline(is, line); ++cnt)
	{
		pfile->push_back(line);
		std::istringstream line_stream(line);
		for (std::string word; line_stream >> word;) {
			auto& line_no_set = this->word_lines[word];
			if (!line_no_set)
				line_no_set.reset(new lines(), DebugDelete());
			line_no_set->insert(cnt);
		}
	}
}

QueryResult TextQuery::query(const std::string& str) const
{
	static std::shared_ptr<lines> nullset(new lines);
	//必须创建一个动态对象new set<size_t>，这样我们解引用*item.pline_set时不会出错（因为我们不能解引用空指针）
	auto iter = this->word_lines.find(str);
	if (iter != word_lines.end())
		return QueryResult(str, this->pfile, iter->second);
	else
		return QueryResult(str, pfile, nullset);
}

std::ostream& operator<<(std::ostream& os, const QueryResult& item)
{
	os << item.word << " occurs " << item.pline_set->size() << " times:" << std::endl;
	for (const auto& line_No : *item.pline_set)
		os << "\t|___line(" << line_No + 1 << ")  " << (*item.pfile)[line_No] << std::endl;
	return os;
}