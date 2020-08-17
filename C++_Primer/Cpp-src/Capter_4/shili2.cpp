#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	unsigned grade;
	cin >> grade;
	string finalgrade = (grade > 90) ? "high pass" :
		((grade > 75) ? "pass" : (grade > 60 ? "low pass" : "fail"));
	cout << finalgrade << endl;

	string finalgrade_test;
	if (grade > 90)
		finalgrade_test = "high pass";
	else if (grade > 75)
		finalgrade_test = "pass";
	else if (grade > 60)
		finalgrade_test = "low pass";
	else
		finalgrade_test = "fail";
	cout << finalgrade_test << endl;

	return 0;
}
