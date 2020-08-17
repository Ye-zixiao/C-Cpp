#include<iostream>
#include<string>
#include<regex>
#include<stdexcept>
using namespace::std;

bool valid(const smatch& sm) {
	if (sm[1].matched)
		//return sm[3].matched && (!sm[4].matched || sm[4].str() == " ");
		return sm[3].matched && (!sm[4].matched || *(sm[4].first)==' ');
	else
		//return !sm[3].matched && (sm[4].str() == sm[6].str());
		return !sm[3].matched && *(sm[4].first) == *(sm[6].first);
		//return !sm[3].matched;
}

int main(void)
{
	try {
		string phonenum;
		regex re("(\\()?(\\d{3})(\\))?([.-]|[ ]+)?(\\d{3})([-.]|[ ]+)?(\\d{4})");
		while (getline(cin, phonenum)) {
			smatch result;
			for (sregex_iterator iter(phonenum.begin(), phonenum.end(), re), end_iter;
				end_iter != iter; ++iter)
				if (valid(*iter))
					cout << "valid: " << iter->str() << endl;
				else
					cout << "not valid: " << iter->str() << endl;
		}
	}
	catch (regex_error& err) {
		cout << err.what() << ' ' << err.code() << endl;
	}

	return 0;
}
