#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace::std;

int main(void)
{
	vector<string> strvec{ "hello","world","","","show","" };
	function<bool(const string&)> fcn = &string::empty;
	cout << count_if(strvec.begin(), strvec.end(), fcn) << endl;

	return 0;
}
