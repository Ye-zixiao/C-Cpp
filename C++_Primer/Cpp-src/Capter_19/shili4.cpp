#include<iostream>
#include<memory>
#include<string>
#include<cstdlib>
#include<stdexcept>
using namespace::std;

void* operator new(size_t sz) {
	cout << "void* operator new(size_t)" << endl;
	if (void* mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void* mem) {
	cout << "void operator delete(void *mem)" << endl;
	free(mem);
}

class Test {
public:
	Test(const string& str);
	~Test();

	size_t size(void) const;
	string* begin(void) {
		return pbegin;
	}
	string* end(void) {
		return pend;
	}

private:
	string* pbegin = nullptr;
	string* pend = nullptr;
	static allocator<string> alloc;
};

Test::Test(const string& str) {
	pbegin = alloc.allocate(10);
	pend = pbegin;
	while (pend != pbegin + 10)
		alloc.construct(pend++, str);
}

Test::~Test() {
	if (pbegin) {
		while (pend != pbegin)
			alloc.destroy(--pend);
		alloc.deallocate(pbegin, 10);
	}
}

size_t Test::size(void) const {
	return pend - pbegin;
}

allocator<string> Test::alloc;

int main(void)
{
	Test item("hello");
	for (auto iter = item.begin(); iter != item.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}
