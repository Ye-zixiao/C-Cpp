#include<iostream>
using namespace::std;

class UseTest;

class Test{
    friend class UseTest;/*友元声明，因为友元是类所以不强制类必须在Test前面声明，
                        但必须保证Test中的成员函数调用友元类中的成员函数时必须保
                        证类UseTest友元类对于友元声明的类中的成员函数可见*/
public:
    Test()=default;
    Test(int val):value(val){}
    int get_value(const UseTest&ut) const;

private:
    int value=0;
};

/*
inline int Test::get_value(const UseTest&ut) const
            /*因为UseTest类虽然被声明过了，但是由于友元声明的类Test的
            成员函数get_value使用了UseTest的实体，所以必须必须要求UseTest在之前就必须被定义，这次的性质不一样了*//*
{
    return ut.get_value(*this);
}
*/

class UseTest{
public:
    UseTest()=default;
    //UseTest(int val):value(val){}
    int get_value(const Test&item) const{ return item.value;}

private:

};

///*
inline int Test::get_value(const UseTest&ut) const
{
    return ut.get_value(*this);
}
//*/

int main(void)
{
    Test test(5);
    UseTest ut;
    cout<<test.get_value(ut)<<endl;

    return 0;
}
