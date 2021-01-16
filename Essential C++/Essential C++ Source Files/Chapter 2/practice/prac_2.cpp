#include<iostream>
#include<vector>
#include<string>
using namespace std;

const vector<int> *create_penta_seq(int size);  //创建数列，并返回这个数列vector类对象的指针（地址）
bool get_seq_elem(int pos,int &elem);           //返回相应下标位置的Pentagnal数列的数值
inline bool size_is_ok(int size);

int main(void)
{
    int pos;
    int elem;
    cout<<"Please enter the seq_pos: ";
    cin>>pos;
    if(get_seq_elem(pos,elem))
        cout<<elem<<endl;

    return 0;
}

inline bool size_is_ok(int size)
{
    if(size<1||size>100)
    {
        cerr<<"Invalid input!"<<endl;
        return false;
    }
    else
        return true;
}

const vector<int> *create_penta_seq(int size)
{
    static vector<int> pentagonal_seq;

    if(!size_is_ok(size))
        return 0;
    else
    {
        for(int i=pentagonal_seq.size()+1;i<=size;i++)
            pentagonal_seq.push_back(i*(3*i-1)/2);
        return &pentagonal_seq;
    }
}

bool get_seq_elem(int pos,int &elem)
{
    const vector<int> *pseq=create_penta_seq(pos);

    if(!pseq)
        return false;
    else
    {
        elem=(*pseq)[pos-1];
        return true;
    }
}
