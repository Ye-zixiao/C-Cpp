#include<iostream>
#include<string>
using namespace::std;

void print_(void);
void print_(void);//�������������Զ���ظ������Ǻ����Ķ���ֻ����һ��
void print(int value,string str="show me the code!");
void print(int value=10,string str);
/*��֮ǰ�ĺ��������Ѿ�Ϊԭ���ĺ��������е�ĳ�����βθ���Ĭ��ʵ�Σ�
*�ظ��ĺ�������ֻ��Ϊû��Ĭ��ʵ�εĺ����β�����Ĭ��ʵ��
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
