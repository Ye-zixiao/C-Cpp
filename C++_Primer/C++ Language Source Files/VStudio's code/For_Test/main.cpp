#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace::std;

int main(void)
{
	vector<int> ivec(10);
	for (decltype(ivec.size()) i = 0; i < ivec.size(); ++i)
		ivec.push_back(i);

	
		
}