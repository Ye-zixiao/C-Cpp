#include<iostream>
#include<string>
//#include"Sales_data.h"
using namespace::std;

class Employee {
public:
	Employee(const string &na,unsigned gd,unsigned sal,const string &spec):
		name(na),gender(gd),salary(sal),speciality(spec){}
	Employee():Employee("",0,0,""){}
	Employee(const string &na,unsigned gd):Employee(na,gd,0,""){}

private:
	const string name;
	unsigned gender;
	unsigned salary;
	string speciality;
};

int main(void)
{
	Employee emp;
	Employee emp_test1("const", 1);
	Employee emp_test2("const", 1, 1, "TEST");

	return 0;
}
