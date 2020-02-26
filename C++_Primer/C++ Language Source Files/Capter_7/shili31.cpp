#include<iostream>
#include<string>
using namespace::std;

class Test {
public:
	Test() = default;

	static double get_sdvalue(void) { return sdvalue; }
	static int get_svalue(void) { return svalue; }

	/*当静态数据成员在编译过程中编译器会对它进行值替换后仍然无错误的情况下，可以在类外
	不定义和初始化静态数据成员。但是当我们有函数用到静态数据成员且要访问（通过引用或者指针）
	的时候就必须在类外进行静态成员定义和初始化*/
	void test(const int &ref_svalue=svalue){}
	//void test(const int *p_svalue=&svalue){}

private:
	static constexpr double sdvalue = 1.23;
	static constexpr int svalue = 10;
	int arr[svalue];
};


constexpr int Test::svalue;
constexpr double Test::sdvalue;

int main(void)
{
	cout << Test::get_sdvalue() << endl;
	cout << Test::get_svalue() << endl;
	Test test;
	test.test();

	return 0;
}
