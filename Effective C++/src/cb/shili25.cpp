#include<iostream>
#include<new>
#include<cstdlib>

class Test {
public:
	Test(int v):value(v){}
	~Test() = default;
	int get(void) const { return value; }
	static void* operator new(std::size_t size, std::ostream& os);
	static void operator delete(void* p, std::ostream& os) noexcept;
	static void operator delete(void* p)noexcept;

private:
	int value;
};

void* Test::operator new(std::size_t size, std::ostream& os) {
	if (size == 0)
		size = 1;
	if (size != sizeof(Test))
		return ::operator new(size);

	while (true) {
		os << "allocating..." << std::endl;
		if (void* p = malloc(size))
			return p;
		std::new_handler nh(std::set_new_handler(nullptr));
		std::set_new_handler(nh);
		if (nh)(*nh)();
		else
			throw std::bad_alloc();
	}
}

void Test::operator delete(void* p)noexcept {
	if (p == nullptr) return;
	free(p);
}

void Test::operator delete(void* p, std::ostream& os)noexcept {
	os << "error make deleting..." << std::endl;
	if (p == nullptr)return;
	free(p);
}

int main(void) {
	Test* p = new (std::cerr) Test(42);
	std::cout << p->get() << std::endl;
	delete p;

	return 0;
}
