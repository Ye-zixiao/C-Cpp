#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void)
{
	int i=0;
	bool next_seq =true;
	const int seq_size = 18;
	int elem_vals[seq_size] = {
		1,2,3,
		3,4,7,
		2,5,12,
		3,6,10,
		4,9,16,
		5,12,22,
	};
	vector<int> elem_seq(elem_vals, elem_vals + seq_size);//用elem_vals数组对向量vector进行初始化
	string seq_names[] = {
		"Fibonacci",
		"Lucas",
		"Pell",
		"Triangular",
		"Square",
		"Pentagonal",
	};


	while (next_seq == true && i < seq_size)
	{
		int answer;
		char user_rsp;
		cout << "The first two elements of the sequence are:\n"
			<< elem_seq[i] << ", "
			<< elem_seq[i + 1]
			<< "\nSo what is the next element?\n";
		cin >> answer;

		if (answer == elem_seq[i + 2])
		{
			cout << "Very good.Yes, "
				<< elem_seq[i + 2]
				<< " is the next element in the "
				<< seq_names[i / 3] << " sequence.\n";
		}
		else
			cout << "Sorry,you are wrong.\n";

		cout << "Would you like to keep answering?\n";
		cin >> user_rsp;
		if (user_rsp == 'n' || user_rsp == 'N')
		{
			next_seq = false;
			cout << "Good bye.\n";
		}
		i += 3;
	}

	return 0;
}
