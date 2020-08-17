#include<iostream>
#include<string>
using namespace::std;

struct Person {
	Person() = default;
	Person(const string &na,const string&addr):
		name(na),address(addr){}
	Person(istream& is){
		is >> name >> address;
	}

	string get_name(void) const { return name; }
	string get_addr(void) const { return address; }

	string name;
	string address;
};

istream& read(Person& p, istream& is=cin)
{
	return is >> p.name >> p.address;
}

ostream& print(const Person& p, ostream& os = cout)
{
	return os << "\tName:" << p.get_name() << "\n\tAddress:"
		<< p.get_addr() << endl;
}

int main(void)
{
	Person p_test;
	read(p_test);
	print(p_test) << endl;

	Person p_testfor("Ye-xinhai", "NJUPT");
	print(p_testfor) << endl;

	Person p_testtest(cin);
	print(p_testtest) << endl;

	return 0;
}
