#include<iostream>
using namespace std;

template<typename T,T max=9>
class Test
{
public:
	void print(void)
	{
		cout << "hello world!" << endl;
		cout << max << endl;
	}
};

template<typename T,T max=0>				//派生类中的所设置的无类型模板参数会覆盖基类中的无类型模板参数
class SecondTest :public Test<T,max>
{
public:
	void hello_print(void)
	{
		this->print();						//无类型模板派生类调用无类型基类中的非虚函数，不能直接调用。
		(*this).print();
	/*	using Test<T,max>::print;
		print();*/
		Test<T,max>::print();               /*主要原因：
                                            C++的模板中的名称会进行两次查找，称为两阶段查找（two-phase lookup）。
                                        对于一个非依赖型名称（不以任何方式依赖于模板参数的名称），在模板声明进行解析的时候就会进行查找。
                                        但C++标准中规定（14.6.2 3），一个非受限的名称查找的时候将不会考虑依赖型的基类。
                                        所以*/
	}
};

int main(void)
{
	SecondTest<int,10> test;
	test.hello_print();

	return 0;
}
