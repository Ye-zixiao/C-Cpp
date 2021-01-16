#include<iostream>
#include<vector>
#include"seq_num.h"//头文件的顺序也很重要！

int main(void)
{
    enum {ns_fibo,ns_square};                       //使用枚举类型
    const vector<int>* (*ptr_arr[])(int)={fibo_seq,
        square_seq};
    //const vector<int> *pseq=0;
    int pos;
    int elem;

    cout<<"Enter the pos: ";
    cin>>pos;
    if(seq_elem(pos,elem,ptr_arr[ns_fibo]))
        cout<<elem<<endl;

    return 0;
}

const vector<int> *fibo_seq(int size)
{
    static vector<int> fibo_seq;

    if(!size_is_ok(size))
        return 0;
    else
    {
        for(int i=fibo_seq.size();i<size;i++)
        {
            if(i==0||i==1)
                fibo_seq.push_back(1);
            else
                fibo_seq.push_back(fibo_seq[i-1]+fibo_seq[i-2]);
        }

        return &fibo_seq;
    }
}

const vector<int> *square_seq(int size)
{
    static vector<int> square_seq;

    if(!size_is_ok(size))
        return 0;
    else
    {
        for(int i=square_seq.size()+1;i<=size;i++)
            square_seq.push_back(i*i);

        return &square_seq;
    }
}

bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int))//使用了函数指针作为参数
{
    const vector<int> *pseq=(*seq_ptr)(pos);    //函数指针用法1：解引用形式
    //const vector<int> *pseq=seq_ptr(pos);     //函数指针用法2：函数名指针等价形式

    if(!pseq)
    {
        elem=0;
        return false;
    }
    else
    {
        elem=(*pseq)[pos-1];
        return true;
    }
}
