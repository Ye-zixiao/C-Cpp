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

bool fibo_elem(int pos,int &elem)   /*这个函数的巧妙之处在于：
                                        在main函数中函数由取地址符获得了elem的地址，
                                    然后在函数体中又有这个地址反向获得了这个地址上的变量
                                    且这个变量是直接可以在函数中操作的*/
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
