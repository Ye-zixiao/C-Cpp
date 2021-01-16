#include<iostream>
#include<string>
using namespace std;

void print_msg(char ch);
void print_msg(const string& st, int num);
void print_msg(const string& st, int num_1, int num_2);

int main(void)
{
	const string greeting = "Hello world!";

	cout << "Function overloading:" << endl;
	print_msg(greeting, 1);
	print_msg('\t');
	print_msg(greeting, 1, 2);

	return 0;
}

void print_msg(char ch)
{
	cout << ch;
}

void print_msg(const string& st, int num)
{
	cout << st << num << endl;
}


void print_msg(const string& st, int num_1, int num_2)
{
	cout << st << num_1
		<< " and " << num_2 << endl;
}
