#include <iostream>
#include <string>

using namespace std;

class test
{
private:
    static int m_value1;		//定义私有类的静态成员变量
public:
    static int m_value2;		//定义公有类的静态成员变量

public:
    test()                      //构造函数
    {
    	m_value1++;
    	m_value2++;
    }

    int getValue()	            //定义类的普通成员函数
    {
    	return m_value1;
    }

    /*static int get_static_value()
    {
        return m_value1;
    }*/
};

int test::m_value1 = 0;		//类的静态成员变量需要在类外分配内存空间
int test::m_value2 = 0;		//类的静态成员变量需要在类外分配内存空间

int main()
{
    test t1;
    test t2;
    test t3;

    cout << "test::m_value2 = " << test::m_value2 << endl;	//通过类名直接调用公有静态成员变量，获取对象个数
    cout << "t3.m_value2 = " << t3.m_value2 << endl;		//通过对象名直接调用公有静态成员变量，获取对象个数
    cout << "t3.getValue() = " << t3.getValue() << endl;	//通过对象名调用普通函数获取对象个数
                                                                /*普通成员函数可以访问静态成员变量，也可以访问普通成员变量，
                                                                而静态成员函数却只可以访问静态成员变量*/
    //cout << "t3.m_value1= " << t3.m_value1 << endl;
    //cout << "t3.get_static_value= " << t3.get_static_value << endl;
    //cout << "test::m_value1 = " << test::m_value1 << endl;

    return 0;
}
