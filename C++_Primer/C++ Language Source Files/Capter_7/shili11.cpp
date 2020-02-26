#include<iostream>
#include<string>
using namespace::std;

class Person {
	friend istream& read(Person& p, istream& is);
	friend ostream& print(const Person& p, ostream& os);

public:
	Person() = default;
	Person(const string&name_str,const string &addr):
		name(name_str),address(addr){}
	Person(istream& is) { read(*this,is); }
	Person(const string&str):name(str){}

	string get_name(void)const { return name; }
	string get_address(void)const { return address; }

private:
	string name;
	string address;
};

istream& read(Person& p, istream& is = cin)
{
	return is >> p.name >> p.address;
}

ostream& print(const Person& p, ostream& os=cout)
{
	return os << "\tName:" << p.get_name() << "\n\tAddress:"
		<< p.get_address() << endl;
}

int main(void)
{
	Person per("Yexinhai", "NJUPT");
	print(per);

	Person per_test(cin);
	print(per_test);

	Person per_tst;
	read(per_tst);
	print(per_tst);

	return 0;
}
