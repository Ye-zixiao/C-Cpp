#include<iostream>
#include<memory>
#include<cstdlib>
#include<stdexcept>
using namespace::std;

void* operator new(size_t sz) {
	cout << "new" << endl;
	if (void* mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void* mem) {
	cout << "delete" << endl;
	free(mem);
}

int main(void)
{
	int* pvalue = new int(32);
	cout << *pvalue << endl;
	delete pvalue;
	return 0;
}
