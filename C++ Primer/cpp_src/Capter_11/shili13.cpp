#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>
//#include<>
using namespace::std;

class Families {
	friend ostream& operator<<(ostream& os, const Families& item);
	friend istream& operator>>(istream& is, Families& item);
public:
	using member = pair<string, string>;
	using family = vector<member>;
	Families() = default;

private:
	map<string, family> families_data;
};

ostream& operator<<(ostream& os, const Families& item)
{
	for (const auto& family : item.families_data)
	{
		os << "Family name:" << family.first;
		for (const auto& member : family.second)
			os << "\n\tmember:" << member.first << ' ' << member.second;
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, Families& item)
{
	string family_name, member, birthday;
	is >> family_name >> member >> birthday;
	if (is)
		item.families_data[family_name].push_back(make_pair(member, birthday));
	return is;
}

int main(void)
{
	Families _families;
	while (cin >> _families);
	cout << _families << endl;

	return 0;
}
