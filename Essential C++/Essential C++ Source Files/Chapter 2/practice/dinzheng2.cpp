#include<iostream>
#include<vector>
#include<string>
using namespace std;

inline bool size_is_ok(int size);
const vector<int> *pent_seq(int pos);
bool pent_elem(int pos,int &elem);

int main(void)
{
    int elem;
    if(pent_elem(8,elem))
        cout<<elem<<endl;

    return 0;
}

inline bool size_is_ok(int size)
{
    return (size<1||size>100)?false:true;
}

const vector<int> *pent_seq(int pos)
{
    static vector<int> seq;
    if(size_is_ok(pos)&&pos>seq.size())
        for(int i=seq.size()+1;i<=pos;i++)
            seq.push_back(i*(3*i-1)/2);
    return &seq;
}

bool pent_elem(int pos,int &elem)
{
    if(!size_is_ok(pos))
    {
        cerr<<"Invalid input"<<endl;
        elem=0;
        return false;
    }
    else
    {
        const vector<int> *pseq=pent_seq(pos);
        elem=(*pseq)[pos-1];
        return true;
    }
}
