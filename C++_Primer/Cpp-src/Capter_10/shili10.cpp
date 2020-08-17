#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size() ? true : false;
}

template<typename Type>
ostream& operator<<(ostream& os, const vector<Type>& tvec)
{
	for (auto elem : tvec)os << elem << ' '; return os;
}

vector<string>& elimDups(vector<string>& strvec)
{
	cout << "before 1st step: \n\t" << strvec << "  " << strvec.size() << endl;
	sort(strvec.begin(), strvec.end());
	cout << "1st step: \n\t" << strvec << "  " << strvec.size() << endl;
	auto unique_iter = unique(strvec.begin(), strvec.end());
	cout << "2nd step: \n\t" << strvec << "  " << strvec.size() << endl;
	strvec.erase(unique_iter, strvec.end());
	cout << "erase step: \n\t" << strvec << "  " << strvec.size() << endl;
	stable_sort(strvec.begin(), strvec.end(), isShorter);
	cout << "last step:\n\t" << strvec << "  " << strvec.size() << endl;
	return strvec;
}

int main(void)
{
	vector<string> strvec{ "hello","world","show","me","sexy","libility","world","hello" };
	elimDups(strvec);

	return 0;
}
