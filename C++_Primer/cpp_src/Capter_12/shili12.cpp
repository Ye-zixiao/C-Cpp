#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cstring>
using namespace::std;

int main(void)
{
	allocator<int> alloc;
	const auto parr = alloc.allocate(10);
	int value;
	auto p = parr;
	for (; cin >> value && p != parr + 10; ++p)
		alloc.construct(p, value);
	while (p != parr) {
		cout << *(--p) << ' ';
		alloc.destroy(p);
	}
	alloc.deallocate(parr, 10);

	return 0;
}
