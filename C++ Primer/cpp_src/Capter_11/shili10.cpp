#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace::std;

pair<string, int> func(vector<string>& strvec)
{
	if (!strvec.empty())
		//return { strvec.back(),strvec.back().size() };
		//return pair<string, int>(strvec.back(), strvec.back().size());
		return make_pair(strvec.back(), strvec.back().size());
	else
		return pair<string, int>();
}

int main(void)
{
	vector<string> strvec{ "hello","world" };
	pair<string, int> sipair = func(strvec);
	cout << sipair.first << " " << sipair.second << endl;

	return 0;
}
