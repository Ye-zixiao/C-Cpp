#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Test {
public:
	static constexpr double rate = 2.3;
	static const int vecSize = 20;
	static vector<double> dvec;

};

constexpr double Test::rate;
const int Test::vecSize;
vector<double> Test::dvec(vecSize);

int main(void)
{
	cout << Test::rate << endl;
	cout << Test::vecSize << endl;
	for (const auto& elem : Test::dvec)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
