#include<iostream>
#include<cstdlib>
#include<memory>
#include<string>
#include<stdexcept>
using namespace::std;

void* operator new(size_t sz) {
	if (void* mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void* mem) {
	free(mem);
}

class Test {
	static allocator<string> alloc;
	string* pbegin = nullptr;
	string* pend = nullptr;
public:
	Test(size_t n, const string& str) :
		pbegin(alloc.allocate(n)), pend(pbegin + n) {
		for (auto iter = pbegin; pbegin != pend; ++iter)
			alloc.construct(iter, str);
	}
	~Test() {
		if (pbegin) {
			auto iter = pend;
			while (iter != pbegin)
				alloc.destroy(--iter);
			alloc.deallocate(pbegin, pend - pbegin);
		}
	}

	string* begin(void) {
		return pbegin;
	}
	string* end(void) {
		return pend;
	}
	size_t size(void) const {
		return pend - pbegin;
	}
};

allocator<string> Test::alloc;

int main(void)
{
	Test item(10, "string");
	for (auto iter = item.begin(); iter != item.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
