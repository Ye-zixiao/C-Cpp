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
	unsigned int vowelCnt = 0, spaceCnt = 0;
	while (cin >> ch)
	{
		switch (tolower(ch))
		{
		case 'a':case 'e':case 'i':case 'o':case 'u':
			++vowelCnt;
			break;
		case '\t': case '\n': case ' ':
			++spaceCnt;
			break;
		default:
			break;
		}
	}
	cout << "vowelCnt=" << vowelCnt << ' '
		<< "spaceCnt=" << spaceCnt << endl;

	return 0;
}

