#include<iostream>
#include<string>
using namespace::std;

typedef string type;
type initVal(void) { return "string"; }

class Exercise {
public:
	typedef double type;
	type setVal(type);
	type initVal(void) { return 0; }

private:
	int val;
};

Exercise::type Exercise::setVal(type parm)
{
	val = parm + initVal();
	return val;
}

int main(void)
{
	return 0;
}
