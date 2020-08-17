#include<iostream>
#include<vector>
using namespace::std;

int multi=100;//but it is better to declare that constexpr

class Test {
public:
	Test() = default;
	static int get_value(void) { return value; }
	void set(int new_value) { value = new_value; }
	static void set_value(int new_value) { value = new_value*multi; }
	/*静态成员函数与普通成员函数的最大区别就是静态成员可以不依托于对象而
	独立地根据作用域运算符进行调用，当然这不代表根据类对象而调用静态成员函数就不能实现；
	普通成员函数当然也可以对静态数据成员进行读写，但是这种读写调用必须依托于对象而存在时
	才可以实现。静态成员函数可以在不生成具体对象的前提下就可以实现调用！
        但是这也意味着：脱离了具体的类对象而调用的静态成员函数只能对同样不依托于
    类对象而存在的静态数据成员以及不受类对象影响的其他对象（比如全局对象）进行操作*/

private:
	static int value;
};

int Test::value = 10;

int main(void)
{
	Test test;
	cout << Test::get_value() << endl;
	cout << test.get_value() << endl;
	test.set(12);//普通成员函数的调用必须依托于类对象才能实现
	cout << Test::get_value() << endl;
	Test::set_value(13);//静态成员函数不用依托于对象的存在而实现，可以通过作用域运算符进行直接调用
	cout << test.get_value() << endl;

	return 0;
}
