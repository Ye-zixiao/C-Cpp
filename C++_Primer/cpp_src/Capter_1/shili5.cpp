#include<iostream>

/*
int main(void)
{
    int sum=0,value=0;
    while(std::cin>>value)
        sum+=value;

    std::cout<<"Sum is "<<sum<<std::endl;

    return 0;
}
*/

int main(void)
{
    int currVal=0,val=0;
    if(std::cin>>currVal)
    {
        int cnt=1;
        while(std::cin>>val)
        {
            if(val==currVal)
                ++cnt;
            else                                    //���ֵ��ͬ���ͽ�cnt��1�������ӡǰһ��ֵ���ֵĴ���
            {
                std::cout<<currVal<<" occurs "
                    <<cnt<<" times"<<std::endl;
                currVal=val;                        //���Ա�ֵ�����µ�ֵ�����¼���
                cnt=1;
            }
        }
        std::cout<<currVal<<" occurs "              //�������֮�󣬽����һ������������
            <<cnt<<" times"<<std::endl;
    }

    return 0;
}
