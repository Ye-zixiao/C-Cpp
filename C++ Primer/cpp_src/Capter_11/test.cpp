#include<iostream>
#include<string>
#include<algorithm>
using namespace::std;

int main(int args, char* argv[])
{
	string str1(argv[1]), str2(argv[2]);
	int num1 = stoi(str1), num2 = stoi(str2);
	cout << num1 * num2 << endl;

	return 0;
}
