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
        ivalue.push_back(in_num);                   //ʹ��push_back��������ӵ�vector������������е������
    for(int i=0;i<ivalue.size();i++)
        sum+=ivalue[i];
    if(sum)
    {
        average=sum/ivalue.size();                  //ʹ�ö�vector��Ĳ���size()���Ի�������ݳ���
        cout<<"Sum of "<<ivalue.size()
            <<" elements is "<<sum
            <<", and average is "<<average
            <<"."<<endl;
    }
    else
        cout<<"No numbers in the vector.\n";

    return 0;
}
