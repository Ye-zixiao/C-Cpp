#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	string temp, read;
	while (cin >> read)
		if (isupper(read[0]) && read == temp)
		{
			cout << read << " appeared two times" << endl;
			break;
		}
		else
			temp = read;
	if (cin.eof())
		cout << "No word appeared two times" << endl;

	return 0;
}
