#include<iostream>
#include<string>
using namespace::std;

int globalvalue = 1000;


void func(void) {
	int localvalue = 1;
	class localClass {
		friend void func(void);
		//这种方式在gcc并不能使用，一般来说一个类已经定义为局部类了，那么没有必要将一些数据成员定义为private
	public:
		int operator()(void) const {
			cout << "hello world" << endl;
			return 1;
		}
	private:
		int dd = globalvalue;
		//int tryfs = localvalue;
	};

	localClass f;
	int value = f();
	cout << f.dd << endl;
}

int main(void)
{
	func();
	return 0;
}
