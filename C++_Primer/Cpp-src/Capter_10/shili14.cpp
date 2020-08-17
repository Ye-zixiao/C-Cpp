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
	auto unique_iter = unique(strvec.begin(),strvec.end());
	strvec.erase(unique_iter, strvec.end());
	stable_sort(strvec.begin(), strvec.end(), [](const string& s1, const string& s2)
		{return s1.size() < s2.size(); });
	return strvec;
}

void chooseBigSize(vector<string>& strvec, vector<string>::size_type sz)
{
	elimDups(strvec);//是strvec中的字符串唯一性排序
	auto Bigsize_iter = find_if(strvec.begin(), strvec.end(), [sz](const string& s)
		{return s.size() >= sz; });
	cout << "Output size>=" << sz << "'s strvec:\n";
	for_each(Bigsize_iter, strvec.end(), [](const string& s)
		{cout << s << ' '; });
	cout << endl;
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
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include"Sales_data.h"
//using namespace::std;
//
//int main(void)
//{
//	vector<Sales_data> svec{ Sales_data("test"),Sales_data("atest"),Sales_data("show") };
//	sort(svec.begin(), svec.end(), [](const Sales_data& s1, const Sales_data& s2)
//		{return s1.isbn() < s2.isbn(); });
//	for (const auto& elem : svec)
//		cout << elem.isbn() << ' ';
//	cout << endl;
//
//	return 0;
//}
