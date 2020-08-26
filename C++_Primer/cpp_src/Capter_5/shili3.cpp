#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	char ch;
	unsigned  vowelCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u'||ch=='e')
			++vowelCnt;
		cout << ch << endl;
	}
	cout << "This text have " << vowelCnt << " vowel(s)" << endl;

	return 0;
}
