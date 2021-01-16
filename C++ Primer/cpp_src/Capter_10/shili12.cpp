#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

string make_plural(vector<string>::size_type count,const string& str,const string& str_add)
{
	return count > 1 ? str + str_add : str;
}

vector<string>& elimDups(vector<string>& strvec)
{
	sort(strvec.begin(), strvec.end());
	auto end_unique = unique(strvec.begin(), strvec.end());
	strvec.erase(end_unique, strvec.end());
	return strvec;
}

void chooseBiggerSize(vector<string>& strvec, vector<string>::size_type sz)
{
	elimDups(strvec);
	stable_sort(strvec.begin(), strvec.end(), [](const string& s1, const string& s2)
		{return s1.size() < s2.size(); });
	auto iter_begin = find_if(strvec.begin(), strvec.end(), [sz](const string& s)
		{return s.size() >= sz; });
	auto count = strvec.end() - iter_begin;
	cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz << " or longer:" << endl;
	for_each(iter_begin, strvec.end(), [](const string& s)
		{cout << s << ' '; });
	cout << endl;
}

int main(void)
{
	vector<string> strvec{ "hello","show","notability","world","coldersho","me" };
	chooseBiggerSize(strvec, 5);
	for_each(strvec.begin(), strvec.end(), [](const string& s)
		{cout << s << ' '; }); cout << endl;

	return 0;
}
