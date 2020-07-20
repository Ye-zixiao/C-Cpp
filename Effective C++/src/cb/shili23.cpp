#include<iostream>
#include<new>
#define debug
using namespace std;

#undef debug

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh):
		handler(nh){
#ifdef debug
		std::cout << "create NewHandlerHolder" << std::endl;
#endif
	}
	NewHandlerHolder(const NewHandlerHolder&) = delete;
	NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;
	~NewHandlerHolder() {
		std::set_new_handler(handler);
	}

private:
	std::new_handler handler;
};

template<typename T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler p)
		noexcept {
		std::new_handler oldhandler = currentHandler;
		currentHandler = p;
		return oldhandler;
	}

	static void* operator new(std::size_t size)
		throw(std::bad_alloc) {
#ifdef debug
		std::cout << "user-defined operator new" << std::endl;
#endif
		NewHandlerHolder nhh(std::set_new_handler(currentHandler));
		return ::operator new(size);
	}

private:
	static std::new_handler currentHandler;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = nullptr;

class Test :public NewHandlerSupport<Test> {
public:
	Test(int v):value(v){}
	int get(void) const { return value; }

private:
	int value;
};

void outofMem(void) {
	std::cout << "hello world" << std::endl;
	std::set_new_handler(nullptr);
}

int main(void)
{
	Test::set_new_handler(outofMem);
	Test* p = new Test(432);
	std::cout << p->get() << std::endl;
	delete p;

	return 0;
}
