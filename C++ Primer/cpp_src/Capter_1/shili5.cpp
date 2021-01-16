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
            else                                    //如果值相同，就将cnt加1，否则打印前一个值出现的次数
            {
                std::cout<<currVal<<" occurs "
                    <<cnt<<" times"<<std::endl;
                currVal=val;                        //将对比值换成新的值，重新计数
                cnt=1;
            }
        }
        std::cout<<currVal<<" occurs "              //输入结束之后，将最后一个结果进行输出
            <<cnt<<" times"<<std::endl;
    }

    return 0;
}
