#include<iostream>
#include<chrono>
using namespace std;

int main(void)
{
	chrono::system_clock::time_point begin = chrono::system_clock::now();

	int arr[1000] = {};
	for (int i = 0; i < 1000; ++i)
		arr[i] += 1;

	chrono::system_clock::time_point end = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	return 0;
}