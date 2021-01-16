#include<iostream>
#include<vector>
#include<string>
#include<cctype>
//#include"header.h"
using namespace::std;

bool isempty(const string& str)
{
	return str.empty();
}

bool IsUpper(const string& str)
{
	for (auto ch : str)
		if (isupper(ch))
			return true;
	return false;
}

string& ToLower(string& str)
{
	for (auto ch : str)
		ch = tolower(ch);
	return str;
}

void print(const int arr[], size_t size)
{
	for (const int* p = arr; p != arr + size; ++p)
		cout << *p << ' ';
	cout << endl;
}

void print(const int* pbeg, const int* pend)
{
	while (pbeg != pend)
		cout << *pbeg++ << ' ';
	cout << endl;
}

void swap_pointer(int* &lpointer, int* &rpointer)
{
	int* ptemp = lpointer;
	lpointer = rpointer;
	rpointer = ptemp;
}

void print(const int arr[10])
{
	for (size_t i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

int main(void)
{
	cout << (isempty("") ? "empty" : "not empty") << endl;

	string hello = "Hello";
	cout << (IsUpper(hello) ? "have upper" : "no upper") << endl;
	cout << ToLower(hello) << endl;

	int arr[10] = { 1, };
	print(arr, 10);
	print(begin(arr), end(arr));

	int lvalue = 3, rvalue = 9, * plvalue = &lvalue, * prvalue = &rvalue;
	cout << *plvalue <<' '<< *prvalue << endl;
	swap_pointer(plvalue, prvalue);
	cout << *plvalue <<' '<< *prvalue << endl;

	int i = 0, j[2] = { 0,1 };
	print(&i, 1);
	print(begin(j), end(j));

	int arrr[10] = { 1, };
	print(arrr);

	return 0;
}
