#include<iostream>
#include<string>
using namespace::std;

class Account {
public:
	Account(const string &str,double init_amount):
		owner(str),amount(init_amount){}

	void calculate(void) { amount += amount * interestRate; }
	double get_amount(void)const { return amount; }
	static double rate(void) { return interestRate; }
	static void rate(double newrate) { interestRate = newrate; }

private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate(void) { return 0.25; }
};

double Account::interestRate = initRate();

int main(void)
{
	Account test("test", 500);
	test.calculate();
	cout << test.get_amount() << endl;

	return 0;
}
