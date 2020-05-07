#include<iostream>
#include"Vector.h"
#include<vector>
#include<string>
using namespace::std;

int main(void)
{
	Vector<string> strvec{ "hello","world","china","america","england" };
	for (decltype(strvec)::size_type pos = 0; pos != strvec.size(); ++pos)
		cout << strvec[pos] << ' '; cout << endl;
	strvec.insert(strvec.begin(), "value");
	strvec.pop_back();
	strvec.resize(3);
	for (const auto& elem : strvec)
		cout << elem << ' '; cout << endl;
	strvec.clear();
	cout << strvec.size() << endl;

	string str("show me the world");
	strvec.insert(strvec.begin(), std::move(str));
	cout << str << endl;
	cout << str.size() << endl;
	cout << *strvec.begin() << endl;
	cout << strvec.begin()->size() << endl;

	cout << "-----------------" << endl;
	Vector<string> strvec_;
	auto iter = strvec_.insert(strvec_.begin(), "[first insert value]");
	strvec_.insert(iter, "[second insert value]");
	for (const auto& elem : strvec_)
		cout << elem << ' '; cout << endl;

	Vector<int> ivec{ 1,2,34,5,3 };


	return 0;
}