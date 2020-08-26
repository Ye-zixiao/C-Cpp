#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace::std;

int sum_stoi(const vector<string>& ivec)
{
	int sum = 0;
	for (const auto& elem : ivec)
		sum += stoi(elem.substr(elem.find_first_of("-+1234567890")));
	return sum;
}

double sum_stod(const vector<string>& svec)
{
	double sum = 0;
	for (const auto& elem : svec)
		sum += stod(elem.substr(elem.find_first_of("-=.1234567890")));
	return sum;
}

int main(void)
{
	vector<string> svec{ "12","32","adf43" };
	vector<string> svec2{ "1.23","asfd1.43","fsk3.432ds" };
	cout << sum_stoi(svec) << endl;
	cout << sum_stod(svec2) << endl;

	return 0;
}
