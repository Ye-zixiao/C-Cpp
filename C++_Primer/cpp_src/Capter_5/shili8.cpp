#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	string compare, input;
	unsigned cnt = 0;
	while (cin >> input)
	{
		if (input == compare)
			++cnt;
		else
		{
			if(!compare.empty())
				cout << compare << " have appeared " << cnt << " times" << endl;
			cnt = 1;
			compare = input;
		}
	}
	if (input.empty())
		cout << "No data?" << endl;
	else
		cout << compare << " have appeared " << cnt << " times" << endl;

	return 0;
}
