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

    sort(s_vec.begin(),s_vec.end(),greater<int>());//��������
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
        if(f(vec[i],value))//ʹ�ú���ָ�����Ƚ������
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
    for(;(it=find(it,vec.end(),value))!=vec.end();it++)//ֻҪitû��ָ�����һ��Ԫ�ص���һλ�þ�˵��
        count_occurs++;                                 //�������value�������Է���ָ��ͼ���ֵ�Լ�һ��
    return count_occurs;
}
