#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
	string str;
	if (getline(cin, str))
	{
		for (auto& c : str)
			c = toupper(c);

		cout << "After the upper function,the string becomes:\n\t"
			<< str << endl;
		return 0;
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}
}
