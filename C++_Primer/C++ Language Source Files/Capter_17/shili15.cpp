#include<iostream>
#include<string>
#include<regex>
using namespace::std;

/*
邮编：5为数值（-或者没有）？4位数值？
*/

bool valid(const smatch& sm) {
	if (sm[3].matched)
		return true;
	else
		return !sm[2].matched;
}

int main(void)
{
	string postnum;
	regex re("(\\d{5})([- .])?(\\d{4})?");
	while (getline(cin, postnum)) {
		smatch result;
		for (sregex_iterator iter(postnum.begin(), postnum.end(), re), end_iter;
			iter != end_iter; ++iter)
			if(valid(*iter))
				cout << "exsiting phone number: " << iter->str(0) << endl;
	}
	return 0;
}
