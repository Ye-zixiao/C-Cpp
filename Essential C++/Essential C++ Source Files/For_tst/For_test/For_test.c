#include<iostream>
#include<vector>
#include<string>
using namespace std;

void show_seq(vector<int>& seq);
const vector<int>* fibo_seq(int size);

int main(void)
{
	int size;
	cout << "Enter the seq_number of fibonacci: ";
	cin >> size;

	const vector<int>* seq;
	seq = fibo_seq(size);
	if (seq)
		show_seq(*seq);

	return 0;
}

void show_seq(vector<int>& seq)
{
	for (int i = 0; i < seq.size(); i++)
	{
		cout << seq[i]
			<< ((i + 1) % 10 ? " " : "\n");
	}
	cout << endl;
}

const vector<int>* fibo_seq(int size)
{
	const int max_size = 1024;
	vector<int> elems;

	if (size<0 || size>max_size)
	{
		cerr << "invalid size" << endl;
		return 0;
	}

	for (int i = elems.size(); i < size; i++)
	{
		if (0 == i || i == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[i - 1] + elems[i - 2]);
	}

	return &elems;
}
