#include<iostream>
#include<string>
using namespace::std;

void print_(void);
void print_(void);//函数的声明可以多次重复，但是函数的定义只能有一个
void print(int value,string str="show me the code!");
void print(int value=10,string str);
/*当之前的函数声明已经为原来的函数声明中的某几个形参赋予默认实参，
*重复的函数声明只能为没有默认实参的函数形参设置默认实参
*/

int main(void)
{
    print_();
    print();

    return 0;
}

void print_(void)
{
    cout<<"hello world!"<<endl;
    return;
}

void print(int value,string str)
{
    cout<<value<<" and "<<str<<endl;
    return;
}
