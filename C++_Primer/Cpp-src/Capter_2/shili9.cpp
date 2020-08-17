#include<iostream>
#include<string>

struct Sale_data{
    std::string bookNo;
    unsigned units_sold;
    double price;
    double revenue;
};

bool input_data(Sale_data& item)
{
    //std::cout<<"Enter the bookNo,units_sold and price:"<<std::endl;
    if(std::cin>>item.bookNo>>item.units_sold>>item.price)
    {
        item.revenue=item.price*item.units_sold;
        return true;
    }
    else
        return false;
}

int main(void)
{
    Sale_data total_item,temp_item;
    if(input_data(total_item))
    {
        std::cout<<"Enter the next record"<<std::endl;
        while(input_data(temp_item))
        {
            if(temp_item.bookNo==total_item.bookNo)
            {
                total_item.units_sold+=temp_item.units_sold;
                total_item.revenue+=temp_item.revenue;
                if(total_item.units_sold)
                    total_item.price=total_item.revenue/total_item.units_sold;
            }
            else
            {
                std::cout<<"\t"<<total_item.bookNo<<" "<<total_item.units_sold<<" "<<total_item.price
                    <<" "<<total_item.revenue<<std::endl;
                total_item.bookNo=temp_item.bookNo;
                total_item.units_sold=temp_item.units_sold;
                total_item.price=temp_item.price;
                total_item.revenue=temp_item.revenue;
            }
        }

        std::cout<<"\t"<<total_item.bookNo<<" "<<total_item.units_sold<<" "<<total_item.price
                    <<" "<<total_item.revenue<<std::endl;
    }
    else
    {
        std::cerr<<"No data?"<<std::endl;
        return -1;
    }
}
