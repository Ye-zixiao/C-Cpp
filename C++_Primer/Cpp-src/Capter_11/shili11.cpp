#include<string>
#include<iostream>
#include<utility>
#include<vector>
using namespace::std;

vector<pair<string, int>>& func(vector<string>& strvec, vector<int>& ivec, vector<pair<string, int>>& pvec)
{
	size_t len = (strvec.size() < ivec.size()) ? strvec.size() : ivec.size();
	for (size_t i = 0; i < len; ++i)
		//pvec.push_back(make_pair(strvec[i], ivec[i]));
		//pvec.push_back({ strvec[i],ivec[i] });
		pvec.push_back(pair<string, int>(strvec[i], ivec[i]));
	return pvec;
}

int main(void)
{
	vector<pair<string, int>> pvec;
	vector<int> ivec{ 1,2,3,4,5,56,6 };
	vector<string> strvec{ "hello","world","show","code" };

	for (const auto& elem : func(strvec, ivec, pvec))
		cout << elem.first << ' ' << elem.second << endl;
	cout << endl;

	return 0;
}
