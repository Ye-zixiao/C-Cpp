//========使用函数对象和绑定适配器（函数对象适配器）=======
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int> filter_ver2(const vector<int> &vec,int value,less<int> lt);
void display(const vector<int> &vec);

int main(void)
{
    int arr[7]={1,3,4,7,5,4,8};
    vector<int> vec(arr,arr+7);

    //less<int> lt;使用引用的方法直接对函数对象操作
    vector<int> fil=filter_ver2(vec,7,less<int>());//传值的方法，在调用时复制一个函数对象
    display(fil);

    return 0;
}

vector<int> filter_ver2(const vector<int> &vec,int value,less<int> lt)
{
    vector<int> re_vec;
    typename vector<int>::const_iterator iter=vec.begin();
    for(;(iter=find_if(iter,vec.end(),bind2nd(lt,value)))!=vec.end();iter++)
        re_vec.push_back(*iter);
    return re_vec;
}

void display(const vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}
