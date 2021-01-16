#include<iostream>
#include<vector>
using namespace std;

inline bool is_size_ok(int size);           //内联函数：适合于做简单的工作
const vector<int> *fibo_seq(int size);
inline bool fibo_elem(int pos,int &elem);

int main(void)
{
    cout<<"Enter the pos: ";
    int pos;
    cin>>pos;

    int elem;
    if(fibo_elem(pos,elem))
        cout<<elem<<endl;

    return 0;
}

inline bool is_size_ok(int size)                //判断输入数是否合理
{
    if(size<1||size>1024)
    {
        cerr<<"invalid size"<<endl;
        return false;
    }
    else
        return true;
}

const vector<int> *fibo_seq(int size)           //生成需要的vector类对象，并将其地址返回给上一级
{
    static vector<int> seq_elems;

    if(!is_size_ok(size))
        return 0;
    else
    {
        for(int i=seq_elems.size();i<size;i++)
        {
            if(i==0||1==i)
                seq_elems.push_back(1);
            else
                seq_elems.push_back(seq_elems[i-1]+seq_elems[i-2]);
        }
        return &seq_elems;
    }
}

inline bool fibo_elem(int pos,int &elem)        //获得vector类对象的地址，并用指针解引用的方式放回其中的成员
{
    const vector<int> *pseq=fibo_seq(pos);

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
