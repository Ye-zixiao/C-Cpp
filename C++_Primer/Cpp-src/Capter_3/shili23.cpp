#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

int main(void)
{
	vector<unsigned int> scores(11, 0);
	unsigned int grade;
	while (cin >> grade)
	{
		if (grade <= 100)
			++* (scores.begin() + grade / 10);
	}

	for (auto i : scores)
		cout << i << ' ';
	cout << endl;

	return 0;
}
