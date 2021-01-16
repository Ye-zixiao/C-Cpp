#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    vector<int> ivalue;
    int sum=0;
    int average;
    int in_num;

    cout<<"Input some number:(enter 'q' to quit) ";
    while(cin>>in_num)
        ivalue.push_back(in_num);                   //使用push_back将数据添加到vector类对象（容器）中的最后面
    for(int i=0;i<ivalue.size();i++)
        sum+=ivalue[i];
    if(sum)
    {
        average=sum/ivalue.size();                  //使用对vector类的操作size()可以获得其数据长度
        cout<<"Sum of "<<ivalue.size()
            <<" elements is "<<sum
            <<", and average is "<<average
            <<"."<<endl;
    }
    else
        cout<<"No numbers in the vector.\n";

    return 0;
}
