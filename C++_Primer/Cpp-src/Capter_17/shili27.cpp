#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<random>
#include<ctime>
#include<stdexcept>
#include<map>
using namespace::std;

unsigned choose(unsigned end, unsigned seed=time(0)) {
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> uni_for(0, end);
	return uni_for(e);

}

map<string, vector<string>> create_rules(ifstream& ifs) {
	string key, line;
	map<string, vector<string>> ret;
	while (ifs >> key && getline(ifs, line))
		if (!key.empty() && !line.substr(1).empty())
			ret[key].push_back(std::move(line.substr(1)));
	return std::move(ret);
}

const string& transform(const string& str, const map<string, vector<string>>& rules) {
	auto iter = rules.find(str);
	auto size = (iter != rules.end() ? iter->second.size() : 0);
	if (size) {
		auto i = choose(size - 1);
		//cout << i << endl;
		return iter->second[i];
	}
	else
		return str;
}

void text_dispose(istream& is, ifstream& ifs) {
	auto rules = create_rules(ifs);
	string line;ostringstream oss;
	while (getline(is, line)) {
		if (!line.empty()) {
			string word; istringstream iss(line);
			while (iss >> word)
				oss << transform(word, rules) << ' ';
			oss << '\n';
		}
	}
	cout << "\nResults:\n" << oss.str() << endl;
}

int main(void)
{
	ifstream infile("key_world.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	text_dispose(cin, infile);

	return 0;
}
