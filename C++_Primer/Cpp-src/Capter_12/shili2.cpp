#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace::std;

vector<int>* create_vector(void)
{
	return new vector<int>();
}

vector<int>* input_to_vector(vector<int>* pvec)
{
	int value;
	while (cin >> value)
		pvec->push_back(value);
	return pvec;
}

ostream& operator<<(ostream& os, const vector<int>* pvec)
{
	for (const auto& elem : *pvec)
		os << elem << ' ';
	return os;
}

int main(void)
{
	vector<int>* pvec = create_vector();
	input_to_vector(pvec);
	cout << pvec << endl;
	delete pvec;

	return 0;
}
