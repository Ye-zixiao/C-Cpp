#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
using namespace::std;

string word_transform(const string& str, unordered_map<string, string>& rule)
{
	auto ret = rule.find(str);
	return ret != rule.end() ? ret->second : str;
}

unordered_map<string, string> buildRule(ifstream& rule_is)
{
	unordered_map<string, string> rule;
	string key, mapped_value;
	while (rule_is >> key && getline(rule_is, mapped_value))
		try {
			if (!mapped_value.empty())
			{
				//rule[key] = mapped_value.substr(1);
				auto ret = rule.insert({ key,mapped_value.substr(1) });
				if (!ret.second)
					throw runtime_error("Appeared repititive key("+key+"),ignored this mapped value");
			}
			else
				throw runtime_error("no mapped_value for " + key);
		}
		catch (runtime_error& err) {
			cerr << err.what() << endl
				<< "------------" << endl;
		}

	return rule;
}

void text_transform(ifstream& text_is, ifstream& rule_is)
{
	unordered_map<string, string> rule = buildRule(rule_is);
	string line;
	while (getline(text_is, line))
	{
		istringstream line_ss(line);
		string word;
		while (line_ss >> word)
			cout << word_transform(word, rule) << ' ';
		cout << endl;
	}
}

int main(void)
{
	ifstream infile("infile.txt", ifstream::in);
	ifstream rulefile("rulefile.txt", ifstream::in);
	if (!infile && !rulefile)
	{
		cerr << "Can't open related files" << endl;
		return -1;
	}

	text_transform(infile, rulefile);

	return 0;
}
