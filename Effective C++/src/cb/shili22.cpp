#include<iostream>
#include<new>
#include<typeinfo>

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh):
		handler(nh){
		std::cout << "store old handler" << std::endl;
	}
	NewHandlerHolder(const NewHandlerHolder&) = delete;
	NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;
	~NewHandlerHolder() {
		std::cout << "set back new_handler" << std::endl;
		std::set_new_handler(handler);
	}

private:
	std::new_handler handler;
};


class Test {
public:
	Test(int v):value(v){}
	int get(void) const{return value;}

	static std::new_handler set_currentHandler(std::new_handler p) noexcept {
		std::new_handler oldhandler = currentHandler;
		currentHandler = p;
		return oldhandler;
	}

	static void* operator new(std::size_t sz) throw(std::bad_alloc) {
		std::cout << "static void*operator new(size_t)throw(bad_alloc)" << std::endl;
		//若内存分配成功，NewHandlerHolder就会自动销毁将全局new_handler设置回原来的nullptr
		NewHandlerHolder h(std::set_new_handler(currentHandler));
		return ::operator new(sz);
	}

private:
	int value;
	static std::new_handler currentHandler;
};

std::new_handler Test::currentHandler = nullptr;

void outofMem(void) {
	std::cout << "hello world\n";
	std::set_new_handler(nullptr);
}

int main(void)
{
	Test::set_currentHandler(outofMem);
	Test* p = new Test(312);
	std::cout<<p->get()<<std::endl;
	delete p;

	return 0;
}
