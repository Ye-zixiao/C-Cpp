#include<iostream>
#include<vector>
using namespace::std;

class NoDefault {
public:
	NoDefault(int){}//没有默认构造函数

};

class C {
public:
	C(int value=0):my_mem(value){}//它起到了默认构造函数的作用

private:
	NoDefault my_mem;
};

int main(void)
{
	C test;
	vector<C> test_C;//调用了C(int value=0)这个默认构造函数
	//vector<NoDefault> test_nd(10);
	//由于NoDefault类没有默认的构造函数，使得vector无法借由其默认构造函数进行值初始化

	return 0;
}
