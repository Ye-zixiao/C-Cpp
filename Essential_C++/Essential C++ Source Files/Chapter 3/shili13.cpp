#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

bool less_than(int value_1,int value_2);
vector<int> filter_ver1(const vector<int> &vec,int filter_value,bool (*pred)(int,int));
void display(const vector<int> &vec);
int occurs_count(const vector<int> &vec,int value);

int main(void)
{
    int arr[7]={1,3,4,7,5,4,8};
    vector<int> vec(arr,arr+7);

    vector<int> file=filter_ver1(vec,5,less_than);
    display(file);

    cout<<"There are "<<occurs_count(vec,4)<<" number 4"
        <<endl;

    sort(vec.begin(),vec.end(),greater<int>());//greater<int>()产生一个未命名的类模板对象
    display(vec);

    return 0;
}

bool less_than(int value_1,int value_2)
{
    return value_1<value_2?true:false;
}

vector<int> filter_ver1(const vector<int> &vec,int filter_value,bool (*pred)(int,int))
{
    vector<int> re_vec;
    for(int i=0;i<vec.size();i++)
        if(pred(vec[i],filter_value))
            re_vec.push_back(vec[i]);
    return re_vec;
}

int occurs_count(const vector<int> &vec,int value)
{
    typename vector<int>::const_iterator iter=vec.begin();
    int occurs_count=0;
    for(;(iter=find(iter,vec.end(),value))!=vec.end();iter++)
        occurs_count++;//遍历找出在vecto中的所有的value值
    return occurs_count;
}

void display(const vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}
