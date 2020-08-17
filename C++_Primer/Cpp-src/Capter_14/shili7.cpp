#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace::std;

class CompString {
public:
	bool operator()(const string& lhs, const string& rhs)const {
		return lhs.size() < rhs.size();
	}
};

class bigSize {
	size_t size;
public:
	bigSize(size_t n):size(n){}
	bool operator()(const string& str)const {
		return str.size() > size;
	}
};

class StringPrint {
public:
	void operator()(const string& str) const {
		cout << str << '\n';
	}
};

void elimDup(vector<string>& strvec) {
	sort(strvec.begin(), strvec.end());
	auto iter = unique(strvec.begin(), strvec.end());
	strvec.erase(iter, strvec.end());
}

void biggies(vector<string>& strvec, size_t n) {//print the string sequence of the size<10
	elimDup(strvec);
	stable_sort(strvec.begin(), strvec.end(), CompString());
	auto big_iter = find_if(strvec.begin(), strvec.end(), bigSize(n));
	for_each(big_iter, strvec.end(), StringPrint());
}

int main(void)
{
	vector<string> strvec{ "hellohellow","show","world","hello","people's republic of china","programer" };
	biggies(strvec, 5);

	return 0;
}
