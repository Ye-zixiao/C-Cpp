#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	unsigned int grade;
	cin >> grade;
	const vector<string> scores{ "F","D","C","B","A" ,"A++" };
	string lettergrade;
	if (grade < 60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade - 50) / 10];
		if (grade != 100)
			if (grade % 10 > 7)
				lettergrade += '+';
			else if (grade % 10 < 3)
				lettergrade += '-';
	}

	cout << lettergrade << endl;

	return 0;
}
