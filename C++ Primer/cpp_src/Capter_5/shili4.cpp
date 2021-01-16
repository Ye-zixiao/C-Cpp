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
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	while (cin >> ch)
	{
		switch (tolower(ch))
		{
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		default:
			break;
		}
	}
	cout << "aCnt=" << aCnt << ' '
		<< "eCnt=" << eCnt << ' '
		<< "iCnt=" << iCnt << ' '
		<< "oCnt=" << oCnt << ' '
		<< "uCnt=" << uCnt << endl;

	return 0;
}
