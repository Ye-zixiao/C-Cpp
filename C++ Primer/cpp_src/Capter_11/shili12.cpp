#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>
using namespace::std;


int main(void)
{
	map<string, vector<pair<string, string>>> families;

	string family_name;
	cout << "Enter family_name(/q to quit):";
	while (cin >> family_name && family_name != "/q")
	{
		string member_name, birthday;
		cout << "Enter member_name and its birthday(/q to quit):";
		while (cin >> member_name && member_name != "/q" && cin >> birthday)
		{
			cout << "Enter member_name and its birthday(/q to quit):";
			families[family_name].push_back(make_pair(member_name, birthday));
		}
		cout << "Enter family_name(/q to quit):";
	}

	for (const auto& family_elem : families)
	{
		cout << "\tFamily_name:" << family_elem.first << ' ';
		for (const auto& pair_elem : family_elem.second)
			cout << "\n\t\t" << pair_elem.first << "'s birthday:" << pair_elem.second;
		cout << endl;
	}

	return 0;
}
