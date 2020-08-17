#include<iostream>
using std::cout;

int main(void){
    int value=10;
    cout<<value<<std::endl;
    *(&value)=11;
    cout<<value<<std::endl;

    return 0;
}
