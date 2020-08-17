#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

void add_family(map<string, vector<string>>& families)
{
	string last_name, name;
	cout << "Enter last_name:";
	cin >> last_name;
	cout << "Enter first_name<seq>:";
	while (cin >> name)
		if(find(families[last_name].begin(), families[last_name].end(),name)== families[last_name].end())
			families[last_name].push_back(name);
    cin.clear();
}

int main(void)
{
	map<string, vector<string>> families;
	char ch='y';
	while(ch!='q')
    {
        add_family(families);
        cin>>ch;
    }


	for (const auto& family : families)
	{
		cout << "\tfamily last_name:" << family.first
			<< "\n\tfamily member first_name:";
		for (const auto& mem : family.second)
			cout << mem << ", ";
		cout << endl<<endl;
	}
	cout << endl;

	return 0;
}
