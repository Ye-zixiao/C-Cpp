#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	string str, pre_str;
	while (cin >> str)
	{
		if (str == pre_str)
		{
			cout << str << " appeared two times!" << endl;
			break;
		}
		pre_str = str;
	}
	if (!cin)
		cout << "No word appears two times" << endl;

	return 0;
}
