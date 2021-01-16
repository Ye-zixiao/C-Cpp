#include<iostream>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
	vector<unsigned int> scores(11);
	//decltype(scores.size()) grade;
	vector<int>::size_type grade;
	while (cin >> grade)
		if (grade <= 100)
			++scores[grade / 10];

	for (auto& cnt : scores)
		cout << cnt << " ";
	cout << endl;

	return 0;
}
