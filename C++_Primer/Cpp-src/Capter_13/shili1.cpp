#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace::std;

class Employee {
public:
	using e_no = size_t;
	Employee():employee_no(init_value++){}
	Employee(const string&str):
		name(str),employee_no(init_value++){}

	e_no get_eno(void)const {
		return employee_no;
	}
	string get_name(void)const {
		return name;
	}

private:
	static e_no init_value;
	string name;
	e_no employee_no;
};

Employee::e_no Employee::init_value = 10190101;

int main(void)
{
	Employee per1;
	Employee per2("hello");
	cout << per1.get_eno() << ' ' << per1.get_name() << endl;
	cout << per2.get_eno() << ' ' << per2.get_name() << endl;

	return 0;
}
