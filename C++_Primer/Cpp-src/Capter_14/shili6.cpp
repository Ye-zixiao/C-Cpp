#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace::std;

class sizeComp {
	size_t lower, upper;
public:
	sizeComp(size_t l,size_t u):
		lower(l),upper(u){}
	bool operator()(const string& str) const {
		return lower <= str.size() && str.size() <= upper;
	}
};

int main(void)
{
	vector<string> strvec{ "hello","world","hello","show","me","do","a" };
	cout << count_if(strvec.begin(), strvec.end(), sizeComp(1, 9)) << endl;

	return 0;
}
