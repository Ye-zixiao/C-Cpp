#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void)
{
	int i;
	int sum;
	int number_size;
	const int seq_size = 20;
	int arr[seq_size];
	vector<int> sequence(seq_size);

	cout << "Please enter some numbers for this program." << endl;
	for (i = 0; i < seq_size; i++)
	{
		int num;
		if (!i)
			cout << "Enter the first one: ";
		else if (i == seq_size - 1)
			cout << "Enter the last one: ";
		else
			cout << "Enter the next one: ";
		cin >> num;
		arr[i] = num;

		cout << "Would you like to enter another number?(y/n) ";
		char user_rsp;
		cin >> user_rsp;
		if (user_rsp == 'n' || user_rsp == 'N')
			break;
	}
	number_size = i+1;
	sum = 0;
	for (i = 0; i < number_size; i++)
		sum += arr[i];
	cout << "The sum of this seq is " << sum << ".\n";

	cout << "Please enter some numbers for vector." << endl;
	for (i = 0; i < seq_size; i++)
	{
		int num;
		if (!i)
			cout << "Enter the first one: ";
		else if (i == seq_size - 1)
			cout << "Enter the last one: ";
		else
			cout << "Enter the next one: ";
		cin >> num;
		sequence[i] = num;

		cout << "Would you like to enter another number?(y/n) ";
		char user_rsp;
		cin >> user_rsp;
		if (user_rsp == 'n' || user_rsp == 'N')
			break;
	}
	number_size = i+1;
	sum = 0;
	for (i = 0; i < number_size; i++)
		sum += sequence[i];
	cout << "The sum of this seq is " << sum << ".\n";

	return 0;
}
