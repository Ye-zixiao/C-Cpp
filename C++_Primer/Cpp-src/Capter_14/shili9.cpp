#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace::std;
using namespace std::placeholders;

bool f(int value, const vector<int>& ivec) {
	modulus<int> mod;
	auto pre = [&](int val) {return mod(value, val) == 0; };
	return all_of(ivec.begin(), ivec.end(), pre);
}

int main(void)
{
	vector<int> ivec{ 1,2,4,3,6,3,2,1,45,76,45,256,4,342 };
	cout << count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 10)) << endl;
	cout << count_if(ivec.begin(), ivec.end(), [](const int& i) {return i > 10; }) << endl;

	vector<string> strvec{ "hello","hello","world","hello" };
	auto local = find_if(strvec.begin(), strvec.end(), bind(not_equal_to<string>(), _1, "hello"));
	cout << "The first string not equal to 'hello' is " << *local << endl;

	for_each(ivec.begin(), ivec.end(), [](int& v) {v *= 2; });
	for_each(ivec.begin(), ivec.end(), [](int v) {cout << v << ' '; });
	cout << endl;

	if (f(0,ivec))
		cout << "All can abslotely divided" << endl;
	else
		cout<<"Can't!"<<endl;


	return 0;
}
