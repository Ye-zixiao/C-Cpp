#include<iostream>
#include<cstdlib>
#include<new>
#include<string>

class Base {
public:
	Base(int v):value(v){}
	~Base() = default;

	static void* operator new(std::size_t size);//对于普通什么都不加的函数而言，就等效于它可能会抛出异常,即  noexcept(false);
	static void operator delete(void* p, std::size_t size)noexcept;

	int getval(void) const {
		return value;
	}

private:
	int value;
};

void* Base::operator new(std::size_t size) {
	if (size == 0)
		size = 1;
	else if (size != sizeof(Base))
		return ::operator new(size);

	while (true) {
		std::cout << "allocating..." << std::endl;
		if (void* p = malloc(size))
			return p;

		std::new_handler nh = std::set_new_handler(nullptr);
		std::set_new_handler(nh);

		if (nh)(*nh)();
		else
			throw std::bad_alloc();
	}
}

void Base::operator delete(void* p, std::size_t size) noexcept {
	if (p == nullptr) return;
	if (size != sizeof(Base))
		return ::operator delete(p);
	std::cout << "deleting..." << std::endl;
	free(p);
}

class Derived :public Base {
public:
	Derived(int v,const std::string&s):
		Base(v),str(s){}

	std::string getstr(void) const {
		return str;
	}

private:
	std::string str;
};

void outOfMem(void) {
	std::cout << "hello world" << std::endl;
	std::set_new_handler(nullptr);
}

int main(void)
{
	Base* pbase = new Base(342);
	std::cout << pbase->getval() << std::endl;
	delete pbase;

	Derived* pderived = new Derived(42,"google");
	std::cout << pderived->getstr() << ' ' << pderived->getval() << std::endl;
	delete pderived;

	return 0;
}
