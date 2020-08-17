#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace::std;

class sizeComp {
public:
	sizeComp(size_t n):
		size(n){}
	bool operator()(const string& str)const {
		return str.size() == size;
	}

private:
	size_t size;
};

int main(void)
{
	vector<string> strvec{ "hello","world","world","me","do","a" };
	for (size_t i = 1; i <= 5; ++i) {
		cout << "Size " << i << "'s String has " << count_if(strvec.begin(), strvec.end(), sizeComp(i)) << endl;
	}

	return 0;
}
