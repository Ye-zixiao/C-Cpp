#include<iostream>
#include<string>
using namespace std;        /*�����д��仰��main�����е������������ָ�������ĸ����еģ�
                            /*�磺 std::cout<<"hello world.\n";         */

int main(void)
{
    string user_name_first;
    string user_name_last;
    cout<<"Please enter your first name: ";
    cin>>user_name_first;
    cout<<"Please enter your last name: ";
    cin>>user_name_last;
    cout<<"Good morning,"+user_name_first+" "+user_name_last+".\n";

    int user_tries(0);       //���캯����ʼ���﷨���ȼ������汻ע�͵����
    //int user_tries=0;
    cout<<user_tries
        <<'\n';
    user_tries=9;
    cout<<"Now variable user_tries="
        <<user_tries
        <<".\n";

    return 0;
}
