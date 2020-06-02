#include<iostream>
#include<cstdlib>
#include<memory>
#include<string>
#include<new>
#include<stdexcept>
using namespace::std;

void* operator new(size_t sz) {
	cout << "void *operator new(size_t)" << endl;
	if (void* mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void* mem) noexcept{
	cout << "void operator delete(void *mem) noexcept" << endl;
	free(mem);
}


int main(void)
{
	allocator<string> alloc;
	auto pbegin = alloc.allocate(10);
	auto iter = pbegin;
	while (iter != pbegin + 10)
		alloc.construct(iter++, "hello");
	for (auto It = pbegin; It != pbegin + 10; ++It)
		cout << *It << ' ';
	cout << endl;
	while (iter != pbegin)
		alloc.destroy(--iter);
	alloc.deallocate(pbegin, 10);
	return 0;
}
