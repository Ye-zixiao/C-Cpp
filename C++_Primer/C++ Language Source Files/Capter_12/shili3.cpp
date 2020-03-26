#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace::std;

shared_ptr<vector<int>> create_vec(void)
{
	return make_shared<vector<int>>();
}

vector<int>& input_tovec(shared_ptr<vector<int>>& pvec)
{
	int value;
	while (cin >> value)
		pvec->push_back(value);
	return *pvec;
}

ostream& operator<<(ostream& os, const vector<int>& vec)
{
	for (const auto& elem : vec)
		os << elem << ' ';
	return os;
}

int main(void)
{
	shared_ptr<vector<int>> pvec(create_vec());
	cout << input_tovec(pvec) << endl;

	shared_ptr<int> pvalue;
	//pvalue = new int(100);
	pvalue = shared_ptr<int>(new int(100));

	return 0;
}
