#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

class PrintString {
public:
	PrintString() = default;
	PrintString(ostream&o,char c):
		sep(c),os(o){}

	void operator()(const string& str) {
		os << str << sep;
	}

private:
	char sep = ' ';
	ostream& os = cout;
};

int main(void)
{
	vector<string> strvec{ "hello","world","show","me","the","code" };
	for_each(strvec.begin(), strvec.end(), PrintString(cout,'\n'));
	cout << endl;

	return 0;
}
