#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void show_seq(const vector<int> &seq,const string &st,ostream &os=cout);//初始化只能进行一次
void pent_seq_create(int size,vector<int> &seq);
inline size_is_ok(int size);

int main(void)
{
    vector<int> seq;
    int size;
    cout<<"Enter the size of pentagonal sequence: ";
    cin>>size;
    pent_seq_create(size,seq);
    ofstream outfile("outdata.txt");
    show_seq(seq,"This is pentagonale sequence:",outfile);

    return 0;
}

void show_seq(const vector<int> &seq,const string &st,ostream &os)
{
    os<<st<<endl;
    for(int i=0;i<seq.size();i++)
    {
        os<<seq[i]
            <<((i+1)%10? " ":"\n");
    }
    os<<endl;
}

void pent_seq_create(int size,vector<int> &seq)
{
    if(!size_is_ok(size))
        return;
    else
    {
        for(int i=1;i<=size;i++)
            seq.push_back(i*(3*i-1)/2);
    }
}

inline size_is_ok(int size)
{
    if(size<1||size>100)
    {
        cerr<<"Invalid input!"<<endl;
        return false;
    }
    else
        return true;
}
