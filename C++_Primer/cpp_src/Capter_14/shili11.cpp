#include<iostream>
#include<functional>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace::std;

int add(int a, int b) {
	return a + b;
}

class Mod {
public:
	int operator()(int a, int b) const {
		return a % b;
	}
};

int main(void)
{
	Mod mod;
	auto minus = [](int a, int b) {return a - b; };
	unordered_map<string, function<int(int, int)>> ops{
		{"+",add},{"*",[](int a,int b) {return a * b; }},
		{"/",divides<int>()},{"%",mod},{"-",minus}
	};

	cout << ops["+"](10, 21) << endl;
	cout << ops["*"](11, 2) << endl;
	cout << ops["-"](10, 32) << endl;
	cout << ops["/"](21, 3) << endl;
	cout << ops["%"](21, 3) << endl;

	return 0;
}
