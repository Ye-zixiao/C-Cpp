#include<iostream>
#include<string>
#include<vector>
using namespace::std;

template<typename Type>
void check(vector<Type> &v);

int main(void)
{
	vector<int> v1;
	check(v1);

	vector<int> v2(10);
	check(v2);

	vector<int> v3(10, 42);
	check(v3);

	vector<int> v4{ 10 };
	check(v4);

	vector<int> v5{ 10,42 };
	check(v5);

	vector<string> v6{ 10 };
	check(v6);

	vector<string> v7{ 10,"hi" };
	check(v7);

	return 0;
}

template<typename Type>
void check(vector<Type> &v)
{
	cout << "Size is " << v.size() << endl;
	cout << "The body is: ";
	for (auto element : v)
		cout << element << " ";
	cout << endl;

	return;
}
