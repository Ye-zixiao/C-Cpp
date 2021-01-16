#include<iostream>
using namespace std;

bool fibo_elem(int pos,int &elem);

int main(void)
{
    cout<<"Enter the seq_num: ";
    int pos;
    int elem;
    cin>>pos;

    if(fibo_elem(pos,elem))
        cout<<"Result:"<<elem<<endl;
    else
        cout<<"Input error"<<endl;

    return 0;
}

bool fibo_elem(int pos,int &elem)   /*�������������֮�����ڣ�
                                        ��main�����к�����ȡ��ַ�������elem�ĵ�ַ��
                                    Ȼ���ں����������������ַ�������������ַ�ϵı���
                                    �����������ֱ�ӿ����ں����в�����*/
{
    if(pos<1||pos>1024)
    {
        elem=-1;
        return false;
    }
    else
    {
        int num_1=1,num_2=1;
        elem=1;

        for(int i=3;i<=pos;i++)
        {
            elem=num_1+num_2;
            num_1=num_2;
            num_2=elem;
        }

        return true;
    }
}
