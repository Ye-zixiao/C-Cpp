#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<stdexcept>
using namespace::std;

map<string, string> buildRule(ifstream& rule_file)
{
	map<string, string> rule;
	string key, mapped_value;
	while (rule_file >> key && getline(rule_file, mapped_value))
        try{
            if (!mapped_value.empty())
                //rule[key] = mapped_value.substr(1);
                rule.insert({key,mapped_value.substr(1)});
            else
                throw runtime_error("no value for " + key);
        }catch(runtime_error&err){
            cerr<<err.what()<<endl
                <<"And we dump it"<<endl<<endl;
        }

	return rule;
}

string word_Transform(const string& str, const map<string, string>& trans_rule)
{
	auto value_iter = trans_rule.find(str);
	return value_iter != trans_rule.end() ? value_iter->second : str;
}

void text_transform(ifstream& rule_is, ifstream& text_is)
{
	map<string, string> rule = buildRule(rule_is);
	string textline;
	while (getline(text_is, textline))
	{
		string word;
		istringstream line_iss(textline);
		while (line_iss >> word)
			cout << word_Transform(word, rule) << ' ';
		cout << endl;
	}
}

int main(void)
{
	ifstream text("infile.txt", ifstream::in);
	ifstream rule("rulefile.txt", ifstream::in);
	if (!text && !rule)
	{
		cerr << "Can't open related files" << endl;
		return -1;
	}
	text_transform(rule, text);

	return 0;
}
