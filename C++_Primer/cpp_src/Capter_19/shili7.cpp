#include<iostream>
#include<cstdlib>
#include<new>
using namespace::std;

void operator delete(void* mem) noexcept {
	cout << "ordinary delete" << endl;
	free(mem);
}

void operator delete(void* mem,const nothrow_t& nt) noexcept {
	cout << "nothrow delete" << endl;
	free(mem);
}

//void operator delete(void* mem, void* second_ptr) noexcept {
//	cout << "placement delete" << endl;
//	free(mem);
//}

struct Test {
	Test() {
		throw 1;
	}
};

struct Raw {
	Raw() = default;
};

int main(void)
{
	//int* pvalue = new (nothrow) int(42);
	//delete pvalue;

	//try {
	//	//new (nothrow) Test();
	//	auto p = new (nothrow) Test();
	//}
	//catch (int& err) {
	//	cerr << err << endl;
	//}

	//int* pv = new int(5);
	//delete pv;

	try {
		auto p = new Raw();
		new (p) Test();//在试图使用定位new在指定指针所指向的位置上创建新的对象，但是由于抛出了对象，若它们调用的普通delete或者是nothrow delete
						//那么它们应该会打印相关的输出，但是这个代码中在创建失败的情况下并没有调用自定义的delete函数，说明它调用的是标准库中定义的
						//定位operator delete函数，而这个定位operator delete函数是不能被重载的（和定位operator new函数相同，都是不能重载的）
	}
	catch (const int& err) {
		cerr << err << endl;
	}

	return 0;
}
