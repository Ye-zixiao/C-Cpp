#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace::std;

int main(void)
{
	multimap<string, vector<string>> families;
	//auto msg = "Enter new family's last name(/q to quit):";
	//auto msg_f = "Enter family's member's first name(/q to quit):";
	//cout << msg;
	for (string lname; cin >> lname&&lname!="/q";)
	{
		//cout << msg_f;
		vector<string> member_name;
		for (string fname; cin >> fname&&fname!="/q";)
			member_name.push_back(fname);
		families.insert({ lname,member_name });
		//cout << msg;
	}

	for (const auto& family : families)
	{
		cout << "Family name:" << family.first << endl;
		for (const auto& mem : family.second)
			cout << "\tmember name:" << mem << endl;
	}

	return 0;
}
