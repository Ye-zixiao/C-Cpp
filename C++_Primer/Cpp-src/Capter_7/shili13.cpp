#include<iostream>
#include<string>
using namespace::std;

class Y;

class X {

private:
	Y* pY = 0;
};

class Y {
private:
	X xobject;
};

int main(void)
{
	return 0;
}
