#include<iostream>
#include<string>
using namespace std;

class Test {
public:
	Test(const string&s):str(s){}

	const string& get(void) const {
		return str;
	}

	string& get(void) {
		//return const_cast<string&>(static_cast<const Test&>(*this).get());
		return const_cast<string&>(static_cast<const Test*>(this)->get());
	}

private:
	string str;
};

int main(int argc, char** argv)
{
	Test item("hello world");
	item.get() = "hello joker";
	cout << static_cast<const Test&>(item).get() << endl;

	return 0;
}
