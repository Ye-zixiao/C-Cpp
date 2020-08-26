#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace::std;

template<typename T>
size_t count_value(const vector<T>& value_vec, T value) {
	size_t cnt = 0;
	for (const auto& elem : value_vec)
		if (elem == value)
			++cnt;
	return cnt;
}

template<>
size_t count_value(const vector<const char*>& value_vec, const char* pc) {
	size_t cnt = 0;
	for (const auto& elem : value_vec)
		if (strcmp(elem, pc) == 0)
			++cnt;
	return cnt;
}

int main(void)
{
	vector<string> strvec{ "hello","world","show","hello","test" };
	vector<const char*> ccvec{ "hello","world","show","hello","test","hello","hello","world"};
	vector<int> ivec{ 1,2,3,4,5,6,7,3,2,1,1,43,2,2 };
	vector<double> dvec{ 1.2,3.4,23.2,23.22,6.45,32.2,12.3,3.4,3.4 };
	cout << count_value(strvec, string("hello")) << endl;
	cout << count_value(ivec, 2) << endl;
	cout << count_value(dvec, 3.4) << endl;
	cout << count_value(ccvec, "hello") << endl;

	return 0;
}
