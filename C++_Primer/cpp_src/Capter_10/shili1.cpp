#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace::std;

int main(void)
{
	int arr[10] = { 1,2,3,4,5,6,65,75,5,6 };
	vector<int> ivec(begin(arr), end(arr));
	cout << count(ivec.begin(), ivec.end(), 6) << endl;

	string str_arr[10] = { "hello","world","hello","joke","show","me","hello" };
	vector<string> strvec(begin(str_arr), end(str_arr));
	cout << count(strvec.begin(), strvec.end(), "hello") << endl;

	return 0;
}
