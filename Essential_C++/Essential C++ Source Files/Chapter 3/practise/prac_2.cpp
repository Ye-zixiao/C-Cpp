#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

void add_family(map<string, vector<string> >& family);
bool search_family(const map<string, vector<string> >& family, string family_name);

int main(void)
{
	map<string, vector<string> > family;
	add_family(family);                     //要求用户添加数据

	string family_name;
	cout << "You want to search a family?";
	cin >> family_name;
	if (search_family(family, family_name))//查找用户要求的数据是否存在
	{
		typename vector<string>::const_iterator iter = family[family_name].begin();
		cout << "Family members are as following:" << endl;
		for (; iter != family[family_name].end(); iter++)
		{
			cout << *iter << ' ';
		}
		cout << endl;
	}

	return 0;
}

void add_family(map<string, vector<string> >& family)
{
	string family_name;
	cout << "Do you want to add family members?(y/n)" << endl;
	cin >> family_name;
	while (family_name != "no")
	{
		string name;
		cout << "Please enter your child name: ";
		while (name!="no")
		{
			family[family_name].push_back(name);
			cout << "Keep enter?(no to quit,otherwise is name) ";
			cin >> name;
		}
		cout << "Do you want to keep adding?(n0 to quit,otherwise to add) ";
		cin >> family_name;
	}
}

bool search_family(const map<string, vector<string> >& family, string family_name)
{
	if (!family.count(family_name))
		return false;
	else
		return true;
}
