#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

bool less_than(int,int);
bool greater_than(int,int);
vector<int> filter(const vector<int> &vec,int value,bool (*f)(int,int));
void display(const vector<int> &vec);
int count_occurs(const vector<int> &vec,int value);

int main(void)
{
    int arr[6]={2,5,8,11,5,12};
    vector<int> s_vec(arr,arr+6);
    vector<int> d_vec;

    sort(s_vec.begin(),s_vec.end(),greater<int>());//倒序排列
    display(s_vec);

    cout<<count_occurs(s_vec,5)<<endl;

    d_vec=filter(s_vec,9,less_than);
    display(d_vec);

    return 0;
}

bool less_than(int x,int y)
{
    return x<y?true:false;
}

bool greater_than(int x,int y)
{
    return x>y?true:false;
}

vector<int> filter(const vector<int> &vec,int value,bool (*f)(int,int))
{
    vector<int> nvec;

    for(int i=0;i<vec.size();i++)
        if(f(vec[i],value))//使用函数指针代替比较运算符
            nvec.push_back(vec[i]);
    return nvec;
}

void display(const vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}

int count_occurs(const vector<int> &vec,int value)
{
    typename vector<int>::const_iterator it=vec.begin();
    int count_occurs=0;
    for(;(it=find(it,vec.end(),value))!=vec.end();it++)//只要it没有指向最后一个元素的下一位置就说明
        count_occurs++;                                 //存在这个value数，所以泛型指针和计数值自加一次
    return count_occurs;
}
