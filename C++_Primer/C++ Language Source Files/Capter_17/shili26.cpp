#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<ctime>
#include<random>
using namespace::std;

//unsigned choose(unsigned end ,unsigned seed = time(0)) {
//	static default_random_engine e(seed);
//	static uniform_int_distribution<unsigned> uni_dis(0, end);
//	return uni_dis(e);
//}

map<string, vector<string>> create_map(ifstream& ifs) {
	map<string, vector<string>> ret;
	string key, line;
	while (ifs >> key && getline(ifs, line)) {
		if (!key.empty() && !line.empty())
			ret[key].push_back(line.substr(1));
	}
	return ret;
}

string transtring(const string& str, const map<string, vector<string>>& rules) {
	auto iter = rules.find(str);
	auto endi = (iter != rules.end() ? iter->second.size() : 0);
	cout << endi << endl;
	if (endi != 0) {
		static default_random_engine e(time(0));
		static uniform_int_distribution<unsigned> uni_dis(0, endi - 1);
		unsigned cnt = uni_dis(e);
		return iter->second[cnt];
	}
	else
		return str;
}

void tranform(istream& is, ifstream& ifs) {
	auto rules = create_map(ifs);
	for (const auto& elem : rules) {
		cout << elem.first << ' ' << elem.second.size() << endl;
	}
	string line;
	ostringstream oss;
	while (getline(is, line)) {
		if (!line.empty()) {
			string word;
			istringstream iss(line);
			while (iss >> word) {
				//cout << word << word.size();
				string temp = transtring(word, rules);
				//cout << temp << temp.size();
				oss << temp << ' ';
			}
			oss << '\n';
		}
	}
	cout << "Result:" << endl;
	cout << oss.str() << endl;
}

int main(void)
{
	ifstream infile("key_world.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}

	tranform(cin, infile);
	infile.close();

	return 0;
}
