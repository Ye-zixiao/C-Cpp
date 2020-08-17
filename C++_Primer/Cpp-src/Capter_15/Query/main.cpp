#include<iostream>
#include"Query.h"
using namespace::std;

int main(void)
{
    Query q=Query("hello")&Query("world")|Query("show");
    cout<<endl;
    cout<<q.rep()<<endl;

    return 0;
}
