#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace::std;

class Sales_data{
    friend istream& read(Sales_data&item,istream&is);
    friend ostream& print(const Sales_data&item,ostream&os);
public:
    Sales_data(const string &str,unsigned us,double price):
        bookNo(str),units_sold(us),revenue(price*units_sold){}
    Sales_data():Sales_data("",0,0){}
    Sales_data(const string &str):Sales_data(str,0,0){}

    string isbn() const {return bookNo;}
    const Sales_data &combine(Sales_data&item);

private:
    double avg_price(void)const {return units_sold?revenue/units_sold:0;}
    string bookNo;
    unsigned units_sold;
    double revenue;
};

istream &read(Sales_data&item,istream&is=cin)
{
    double price;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}

ostream& print(const Sales_data&item,ostream&os=cout)
{
    return os<<"bookNo:"<<item.bookNo
        <<"\nunits_sold:"<<item.units_sold<<endl
        <<"revenue:"<<item.revenue<<endl
        <<"avg_price:"<<item.avg_price()<<endl;
}

const Sales_data& Sales_data::combine(Sales_data&item)
{
    units_sold+=item.units_sold;
    revenue+=item.revenue;
    return *this;
}

int main(void)
{
    const string filename="outfile.txt";
    ofstream out(filename,ofstream::out|ofstream::app);
    if(!out)
    {
        cerr<<"Error"<<endl;
        return -1;
    }

    Sales_data total;
    if(read(total))
    {
        Sales_data trans;
        while(read(trans))
        {
            if(trans.isbn()==total.isbn())
                total.combine(trans);
            else
            {
                print(total,out)<<endl;
                total=trans;
            }
        }
        print(total,out)<<endl;
    }
    else
        cerr<<"No data?"<<endl;


    out.close();
    return 0;
}
