#include<set>
#include<string>
#include<iostream>
#include<map>
using namespace::std;

int main(void)
{
	map<string, set<int>> ssimap;
	ssimap.insert({ "hello",{1,2,3} });
	auto& lines = ssimap["hello"];
	if (!lines)
	{

	}

}