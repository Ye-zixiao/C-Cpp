#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

class ReadString {
public:
	string operator()(istream& is=cin) {
		string temp;
		return getline(is,temp) ? temp : "";
	}
};

class PrintString {
public:
	PrintString(char c = ' ', ostream& o = cout):
		sep(c),os(o){}

	void operator()(const string& str)const {
		os << str << sep;
	}

private:
	char sep;
	ostream& os;
};

int main(void)
{
	vector<string> strvec;
	ReadString rs;
	string str;
	while (!(str = rs()).empty())
		strvec.push_back(str);

	for_each(strvec.begin(), strvec.end(), PrintString('\n',cout));
	cout << endl;

	return 0;
}
