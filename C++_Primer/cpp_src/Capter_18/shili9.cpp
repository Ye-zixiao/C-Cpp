#include<iostream>
#include<string>
using namespace::std;

class Test {
public:
	int value = 10;
};

static string hello = "fuck";
static Test item;

namespace nsp {
	namespace in_nsp {
		unsigned operator*(const string& lhs, const string& rhs) {
			return lhs.size() * rhs.size();
		}
	}
}

namespace {
	string static_str("hello");
}

using nsp::in_nsp::operator*;

int main(void)
{
	string str1("hello"), str2("world");
	cout << str1 * str2 << endl;

	cout << static_str << endl;
	cout << hello << endl;
	cout << item.value << endl;

	return 0;
}
