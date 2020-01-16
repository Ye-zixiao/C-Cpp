#include<iostream>
#include<string>
#include"Sales_item.h"

/*
int main(void)
{
    Sales_item book;
    std::cout<<"Please enter a string of ISBN and number and the price:\n";
    while(std::cin>>book)
    {
        std::cout<<"Record:"<<book<<std::endl;
    }

    return 0;
}
*/
/*
int main(void)
{
    Sales_item item_1,item_2;
    std::cout<<"Please enter two items:\n";
    std::cin>>item_1>>item_2;
    std::cout<<item_1+item_2<<std::endl;

    return 0;
}
*/
/*
int main(void)
{
    Sales_item item,sum_item;

    std::cout<<"Please enter a set of information:\n";
    while(std::cin>>item)
        sum_item+=item;
    std::cout<<"The summary of these record is "<<sum_item<<std::endl;

    return 0;
}
*/
/*
int main(void)
{
    Sales_item item1,item2;
    std::cout<<"Enter two items:"<<std::endl;
    std::cin>>item1>>item2;
    if(item1.isbn()==item2.isbn())
    {
        std::cout<<item1+item2<<std::endl;
        return 0;
    }
    else
    {
        std::cerr<<"Data must refer to same ISBN."
            <<std::endl;
        return -1;
    }
}
*/
/*
int main(void)
{
    Sales_item book;
    std::cout<<"Input some record for this program:\n";
    if(std::cin>>book)
    {
        int cnt=1;
        std::string isbn=book.isbn();
        while(std::cin>>book)
        {
            if(book.isbn()==isbn)
                ++cnt;
            else
            {
                std::cout<<"Record("<<isbn<<")"
                    <<"has occured "<<cnt<<" times"<<std::endl;
                cnt=1;
                isbn=book.isbn();
            }
        }
        std::cout<<"Record("<<isbn<<")"
                    <<"has occured "<<cnt<<" times"<<std::endl;
    }

    return 0;
}
*/

int main(void)
{
    Sales_item total;
    if(std::cin>>total)//检测了是否读取成功
    {
        Sales_item trans;
        while(std::cin>>trans)
        {
            if(trans.isbn()==total.isbn())
                total+=trans;
            else
            {
                std::cout<<total<<std::endl;
                total=trans;
            }
        }
        std::cout<<total<<std::endl;
    }
    else
    {
        std::cerr<<"No data?"<<std::endl;
        return -1;
    }

    return 0;
}
