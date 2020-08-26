#include<string>
#include<iostream>
#include<utility>
using namespace::std;

int move(int value) {
	return ++value;
}

int main(void)
{
	int value = 100;
	auto result = move(value);
	cout << result << endl;

	return 0;
}
