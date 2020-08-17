#include<iostream>
#include<vector>
#include"String.h"
#include<algorithm>
using namespace::std;

class Condition {
public:
	int operator()(bool cond, int lhs, int rhs) {
		return cond ? lhs : rhs;
	}
};

int main(void)
{
	Condition cond;
	cout << cond(4 < 5, 43, 32) << endl;

	return 0;
}
