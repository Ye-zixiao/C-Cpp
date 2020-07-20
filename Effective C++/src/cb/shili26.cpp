#include<iostream>
#include<cstdlib>
#include<new>

class Base {
public:
	Base(int v):value(v){}
	virtual ~Base() = default;

	int get(void) const { return value; }

	static void* operator new(std::size_t size);
	static void operator delete(void* p)noexcept;

	static void* operator new(std::size_t size, void* ptr);
	static void operator delete(void* p, void* ptr)noexcept;

	static void* operator new(std::size_t size, const std::nothrow_t& nt);
	static void operator delete(void* p, const std::nothrow_t& nt)noexcept;

private:
	int value;
};

void* Base::operator new(std::size_t size) {
	return ::operator new(size);
}

void* Base::operator new(std::size_t size, void* ptr) {
	return ::operator new(size, ptr);
}

void* Base::operator new(std::size_t size, const std::nothrow_t& nt) {
	return ::operator new(size, nt);
}

void Base::operator delete(void* p)noexcept {
	::operator delete(p);
}

void Base::operator delete(void* p, void* ptr)noexcept {
	::operator delete(p, ptr);
}

void Base::operator delete(void* p, const std::nothrow_t& nt)noexcept {
	::operator delete(p, nt);
}

class Derived :public Base {
public:
	using Base::Base;
	using Base::operator new;
	using Base::operator delete;

	static void* operator new(std::size_t size, std::ostream& os);
	static void operator delete(void* p, std::ostream& os) noexcept;
};

void* Derived::operator new(std::size_t size, std::ostream& os) {
	os << "memory allocating..." << std::endl;
	while (true) {
		if (void* p = malloc(size))
			return p;
		std::new_handler nh = std::set_new_handler(nullptr);
		std::set_new_handler(nh);
		if (nh)(*nh)();
		else throw std::bad_alloc();
	}
}

void Derived::operator delete(void* p, std::ostream& os)noexcept {
	os << "memory deallocating..." << std::endl;
	if (p)return;
	free(p);
}

void OutOfMem(void) {
	std::cerr << "memory isn't enough!" << std::endl;
	std::set_new_handler(nullptr);
}

int main(void)
{
	std::set_new_handler(OutOfMem);
	Derived* pnormal = new Derived(34);
	Derived* pderived = new (std::cerr) Derived(32);
	std::cout << pnormal->get() << std::endl;
	std::cout << pderived->get() << std::endl;
	delete pnormal;
	delete pderived;

	return 0;
}
