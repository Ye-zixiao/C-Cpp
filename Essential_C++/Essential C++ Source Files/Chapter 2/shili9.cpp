#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int* parr = new int[24];
	for (int i = 0; i < 24; i++)
		parr[i] = i;
	for (int i = 0; i < 24; i++)
	{
		cout << parr[i];
		cout << ((i+1) % 10 ? " " : "\n");
	}
	cout << endl;

	delete [] parr;

	return 0;
}
