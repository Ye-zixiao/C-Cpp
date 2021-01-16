#include<iostream>
#include<string>
using namespace std;        /*如果不写这句话，main函数中的相关类对象必须指出它是哪个库中的，
                            /*如： std::cout<<"hello world.\n";         */

int main(void)
{
    string user_name_first;
    string user_name_last;
    cout<<"Please enter your first name: ";
    cin>>user_name_first;
    cout<<"Please enter your last name: ";
    cin>>user_name_last;
    cout<<"Good morning,"+user_name_first+" "+user_name_last+".\n";

    int user_tries(0);       //构造函数初始化语法，等价与下面被注释的语句
    //int user_tries=0;
    cout<<user_tries
        <<'\n';
    user_tries=9;
    cout<<"Now variable user_tries="
        <<user_tries
        <<".\n";

    return 0;
}
