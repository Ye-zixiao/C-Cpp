#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

ostream& operator<<(ostream& os, const vector<string>& strvec)
{
	for (const auto& elem : strvec)os << elem << ' '; return os;
}

vector<string>& elimDups(vector<string>& strvec)
{
	sort(strvec.begin(), strvec.end());
	auto unique_iter = unique(strvec.begin(), strvec.end());
	strvec.erase(unique_iter, strvec.end());
	stable_sort(strvec.begin(), strvec.end(), [](const string& s1, const string& s2)
		{return s1.size() < s2.size(); });
	return strvec;
}

void chooseBigSize(vector<string>& strvec, vector<string>::size_type sz)
{
	elimDups(strvec);
	auto iter_end = partition(strvec.begin(), strvec.end(), [sz](const string& s)
                           //若使用了partition就没有必要使用stable_sort来找出符合要求的字符串
		{return s.size() < sz; });
	cout << "size>=" << sz << ":" << endl;
	for_each(iter_end, strvec.end(), [](const string& s)
		{cout << s << ' '; });
}

int main(void)
{
	vector<string> strvec{ "hello","world","showme","niubility","libility","sexy","me","showme","show","me","show" };
	cout << strvec << endl;
	//cout << elimDups(strvec) << endl;

	//输出经过elimDups处理后的strvec（通过拷贝完成）
	vector<string> strvec_cp(strvec.size());
	copy(strvec.begin(), strvec.end(), strvec_cp.begin());
	cout << elimDups(strvec_cp) << endl;

	//输出经过两轮筛选的strvec
	cout << "======================" << endl;
	chooseBigSize(strvec, 5);

	return 0;
}
