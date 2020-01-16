#include<iostream>
#include<vector>
using namespace std;

inline bool size_is_ok(int size);                                       //�ж������Ƿ����
bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int));    //��������λ�õ���ֵ
const vector<int> *fibo_seq(int size);                                  //����Fibonacci����
const vector<int> *square_seq(int size);                                //����ƽ������

int main(void)
{
    enum {ns_fibo,ns_square};                       //ʹ��ö������
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

inline bool size_is_ok(int size)
{
    if(size<1||size>1024)
    {
        cerr<<"Invalid input size!"<<endl;
        return false;
    }
    else
        return true;
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

bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int))//ʹ���˺���ָ����Ϊ����
{
    const vector<int> *pseq=(*seq_ptr)(pos);    //����ָ���÷�1����������ʽ
    //const vector<int> *pseq=seq_ptr(pos);     //����ָ���÷�2��������ָ��ȼ���ʽ

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
