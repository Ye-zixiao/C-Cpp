#include<iostream>
#include<string>
using namespace::std;

class Account {
public:
	Account(const string &str,double init_amount):
		user_name(str),amount(init_amount){}
	Account() = default;

	static double rate(void) { return fund_rate; }
	static void set_rate(double new_rate){ fund_rate=new_rate; }
	//因为static数据成员是私有成员，所以我们需要通过静态成员函数来进行对其进行修改
	double final_amount(int month);
	void set(double new_rate){fund_rate=new_rate;}
	//使用普通成员函数也可以修改静态数据成员的值？

private:
	string user_name;
	double amount;
	static double fund_rate;

};

double Account::final_amount(int month)
{
	for (int i = 0; i < month; ++i)
		amount += amount * rate();
	return amount;
}

double Account::fund_rate = 0.12;

int main(void)
{
	Account user("Ye-zixiao", 6200);
	cout<<Account::rate()<<endl;
	cout << "After 6 months ,user will have " << user.final_amount(6)
		<< " yuan by investing fund" << endl;

    //Account::set_rate(0.08);
    user.set(0.08);
    Account user_2("Zhang-bin",6000);
    cout<<Account::rate()<<endl;
    cout<<"After 6 months ,user will have "<< user_2.final_amount(6)
        <<" yuan by investing fund"<<endl;

	return 0;
}
