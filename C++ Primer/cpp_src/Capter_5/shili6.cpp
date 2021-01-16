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
	unsigned ffCnt = 0, fiCnt = 0, flCnt = 0;
	bool flag = false;
	while (cin >> ch)
	{
		switch (tolower(ch))
		{
		case 'f':
			if (flag)
			{
				++ffCnt;
				flag = false;
			}
			else
			{
				flag = true;
				continue;
			}
			break;
		case 'i':
			if (flag)
			{
				++fiCnt;
				flag = false;
			}
			break;
		case 'l':
			if (flag)
			{
				++flCnt;
				flag = false;
			}
			break;
		default:
		    flag=false;//���ǰ����ַ�����f����ǰ���ַ�Ҳ������Ҫ���ַ����ͽ�flag��Ϊfalse
			break;
		}
	}
	cout << "ffCnt=" << ffCnt << ' '
		<< "flCnt=" << flCnt << ' '
		<< "fiCnt=" << fiCnt << endl;

	return 0;
}
