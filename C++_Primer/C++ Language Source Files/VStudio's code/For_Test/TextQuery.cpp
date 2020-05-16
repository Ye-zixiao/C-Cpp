#include"TextQuery.h"

/*
*TextQuery��ĳ�Ա����
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
	//���봴��һ����̬����new set<size_t>���������ǽ�����*item.pline_setʱ���������Ϊ���ǲ��ܽ����ÿ�ָ�룩
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