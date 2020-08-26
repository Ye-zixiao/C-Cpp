#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace::std;

vector<string>::size_type
count_empty_1(const vector<string>& strvec) {
	return count_if(strvec.cbegin(), strvec.cend(),
		mem_fn(&string::empty));
}

vector<string>::size_type
count_empty_2(const vector<string>& strvec) {
	return count_if(strvec.cbegin(), strvec.cend(),
		bind(&string::empty, placeholders::_1));
}

vector<string>::size_type
count_empty_3(const vector<string>& strvec) {
	function<bool(const string&)> func = &string::empty;
	return count_if(strvec.cbegin(), strvec.cend(),
		func);
}

int main(void)
{
	vector<string> strvec{ "","show","hello","world","","joker" };
	cout << count_empty_1(strvec) << endl
		<< count_empty_2(strvec) << endl
		<< count_empty_3(strvec) << endl;
	return 0;
}
