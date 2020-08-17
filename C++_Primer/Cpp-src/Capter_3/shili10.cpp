#include<iostream>
#include<vector>
#include<string>
using namespace::std;

int main(void)
{
	int temp;
	vector<int> str_vec;
	while (cin >> temp)
		str_vec.push_back(temp);

	for (auto & str : str_vec)
		cout << str << " ";
	cout << endl;

	return 0;
}
