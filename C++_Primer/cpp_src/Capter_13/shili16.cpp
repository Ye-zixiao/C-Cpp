#include<iostream>
#include<vector>
#include"String.h"
using namespace::std;

int main(void)
{
	vector<String> strvec;
	for (size_t i = 0; i < 10; ++i)
	{
		strvec.push_back("hello");
		/*"hello"以String(const char*cp)的转换构造函数初始化临时对象，原strvec中的元素通过移动构造的方式移动后，
		临时对象通过移动构造“插入”到后面的内存位置。毕竟这个临时对象是一个右值*/
		cout << i << "--------------------" << endl;
	}

	return 0;
}
