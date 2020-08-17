#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

struct Eql {
	Eql(const string&str):
		eql_str(str){}

	bool operator()(const string& str)const {
		//return str == eql_str ? true : false;//这种写法很傻
		return str==eql_str;
	}

private:
	string eql_str;
};


int main(void)
{
	vector<string> strvec{ "hello","world","show","world","hello" };
	replace_if(strvec.begin(), strvec.end(), Eql("world"), "china");
	for_each(strvec.begin(), strvec.end(), [](const string& str) {cout << str << ' '; });
	cout << endl;

	return 0;
}
