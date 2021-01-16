#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace::std;
using namespace std::placeholders;

bool check_size(const string& str, string::size_type sz)
{
	return str.size() >= sz;
}

vector<string>& elimDups(vector<string>& strvec)
{
	sort(strvec.begin(), strvec.end());
	auto unique_end_iter = unique(strvec.begin(), strvec.end());
	strvec.erase(unique_end_iter, strvec.end());
	return strvec;
}

ostream& print(ostream& os, const string& str)
{
	return os << str << ' ';
}

ostream& operator<<(ostream& os, const vector<string>& strvec)
{
	for_each(strvec.begin(), strvec.end(), [&os](const string& str) {print(os, str); });
	return os;
}

void biggies(vector<string>& strvec, vector<string>::size_type sz)
{
	elimDups(strvec);
	cout << strvec << endl;
	stable_sort(strvec.begin(), strvec.end(), [](const string& s1, const string& s2) {return s1.size() < s2.size(); });
	cout << strvec << endl;
	//stable_partition(strvec.begin(), strvec.end(), [sz](const string& str) {return str.size() >= sz; });
	auto false_iter = stable_partition(strvec.begin(), strvec.end(), bind(check_size, _1, sz));
	//for_each(strvec.begin(), false_iter, [](const string& str) {cout << str << ' '; });
	for_each(strvec.begin(), false_iter, bind(print, ref(cout), _1));
}

int main(void)
{
	vector<string> strvec{ "hello","world-wild","show","me","hello","coder","dolly" };
	biggies(strvec, 5);

	return 0;
}
