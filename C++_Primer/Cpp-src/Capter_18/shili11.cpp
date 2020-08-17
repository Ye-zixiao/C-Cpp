#include<iostream>

namespace nsp {
	int ivar;
	double dvar;
	const int limit = 10;
}

int ivar = 19;
//using namespace::nsp;
//using nsp::dvar;
//using nsp::ivar;
//using nsp::limit;

void func() {
	//using nsp::dvar;
	//using nsp::ivar;
	//using nsp::limit;
	using namespace::nsp;

	double dvar = 2.2;
	int iojb = limit + 1;
	++ivar;
	++::ivar;

}

int main(void)
{
	func();
	return 0;
}
