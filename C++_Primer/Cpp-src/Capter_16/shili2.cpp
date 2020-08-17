#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<numeric>
using namespace::std;

template<typename Iterator,typename _Value>
inline Iterator Find(Iterator _First,Iterator _Last,_Value value){
    for(;_First!=_Last&&*_First!=value;++_First);
    return _First;
}

int main(void)
{
	vector<int> ivec(10);
	iota(ivec.begin(), ivec.end(), 1);
	//for (const auto& elem : ivec)cout << elem << ' '; cout << endl;
	cout << *Find(ivec.begin(), ivec.end(), 5) << endl;

	list<string> slist{ "world","hello","show","time","tarball" };
	if (Find(slist.begin(), slist.end(), "fuck") != slist.end())
		cout << "find" << endl;
	else
		cout << "not find" << endl;

	return 0;
}
