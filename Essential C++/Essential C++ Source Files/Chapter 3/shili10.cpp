#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool is_elem(vector<int> &vec,int elem);    //检查elem是否存在
bool grow_vec(vector<int> &vec,int elem);//新添元素并检查elem是否存在
void display(vector<int> &vec);

int main(void)
{
    vector<int> vec;
    int elem=8;
    if(is_elem(vec,elem))
        cout<<elem<<" Find"<<endl;
    else
        cout<<elem<<" Not find"<<endl;
    display(vec);

    return 0;
}

bool is_elem(vector<int> &vec,int elem)
{
    int max_value=vec.empty()?0:vec[vec.size()-1];

    if(max_value<elem)
        return grow_vec(vec,elem);
    else if(max_value==elem)
        return true;
    else
        return binary_search(vec.begin(),vec.end(),elem);
}

bool grow_vec(vector<int> &vec,int elem)//为vec向量类对象添加fibonacci元素，并且判断新添的元素是否等于elem
{
    int i=vec.size();
    do
    {
        if(i==0||i==1)
            vec.push_back(1);
        else
            vec.push_back(vec[i-1]+vec[i-2]);
        if(vec[i]==elem)
            return true;
    }
    while(vec[i++]<elem);
    return false;
}

void display(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}
