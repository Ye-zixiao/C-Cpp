#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	char ch, prechar = '\0';
	unsigned acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0, ficnt = 0, ffcnt = 0, flcnt = 0;
	while (cin >> ch)
	{
		switch (tolower(ch))
		{
		case 'a':++acnt; break;
		case 'i':if (prechar == 'f')++ficnt; ++icnt; break;
		case 'e':++ecnt; break;
		case 'o':++ocnt; break;
		case 'u':++ucnt; break;
		case 'f':if (prechar == 'f')++ffcnt; break;//缺点就是它会重复记ff
		case 'l':if (prechar == 'f')++flcnt; break;
		default:break;
		}
		prechar = ch;
	}
	cout << "a=" << acnt << ' '
		<< "i=" << icnt << ' '
		<< "ecnt=" << ecnt << ' '
		<< "ocnt=" << ocnt << ' '
		<< "ucnt=" << ucnt << ' '
		<< "ffcnt=" << ffcnt << ' '
		<< "flcnt=" << flcnt << ' '
		<< "ficnt=" << ficnt << endl;

	return 0;
}
