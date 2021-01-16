#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
	string temp;
	cin >> temp;
	char* pcarr = new char[temp.size()];
	for (size_t i = 0; i < temp.size(); ++i)
	{
		pcarr[i] = temp[i];
		cout << pcarr[i];
	}
	cout << endl;
	delete[] pcarr;

	return 0;
}
