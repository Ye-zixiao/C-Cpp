#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace::std;
using namespace std::placeholders;

bool check_size(const string& str, string::size_type sz)
{
	return str.size() <= sz;
}

int main(void)
{
	vector<string> strvec{ "hello","world","show","how","foreach" };
	cout << count_if(strvec.begin(), strvec.end(), bind(check_size, _1, 6)) << endl;

	vector<int> ivec;
	for(decltype(ivec)::size_type i=0;i<10;++i)
        ivec.push_back(i);
	string testlen = "hello";
	cout << *find_if(ivec.begin(), ivec.end(), bind(check_size, testlen, _1)) << endl;
	//找到第一个不能比testlen要小的数值

	return 0;
}
