#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>
#include<algorithm>
using namespace::std;

bool valid(const smatch& sm) {
	if (sm[1].matched)
		return sm[3].matched && (!sm[4].matched && sm[4].str() == " ");
	else
		return !sm[3].matched && sm[4].str() == sm[6].str();
}

int main(void)
{
	ifstream infile("phonenum.txt");
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	string line;
	regex re("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	while (getline(infile, line)) {
		vector<string> results;
		for (sregex_iterator iter(line.begin(), line.end(), re), end_iter;
			end_iter != iter; ++iter) {
			results.push_back(iter->format("($2) $5-$7"));
		}
		if (results.size() == 0)
			cout << "No match phonenumber" << endl;
		else if (results.size() == 1)
			cout << results[0] << endl;
		else {
			for_each(results.begin()+1, results.end(), [](const string& pn) {cout << pn << ' '; });
			cout << endl;
		}
	}

	return 0;
}
