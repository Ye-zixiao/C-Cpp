#include <iostream>
#include <string>

using namespace std;

class test
{
private:
    static int m_value;		    //定义私有类的静态成员变量

public:
    test()
    {
    	m_value++;
    }

    static int getValue()		//定义类的静态成员函数
    {
    	return m_value;
    }
};

int test::m_value = 0;		    //类的静态成员变量需要在类外分配内存空间

int main()
{
    test t1;
    test t2;
    test t3;

    cout << "test::m_value2 = " << test::getValue() << endl;	//通过类名直接调用公有静态成员函数，获取对象个数
    cout << "t3.getValue() = " << t3.getValue() << endl;		//通过对象名调用静态成员函数获取对象个数

    return 0;
}
