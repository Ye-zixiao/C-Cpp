#include<iostream>
#include<vector>
#include<string>
using namespace std;

inline int max(int x,int y);
inline double max(double x,double y);
inline char max(char x,char y);

int main(void)
{
    cout<<max(2,3)<<endl;
    cout<<max(1.3,3.4)<<endl;
    cout<<max('x','q')<<endl;

    return 0;
}

inline int max(int x,int y)
{
    return x>y?x:y;
}

inline double max(double x,double y)
{
    return x>y?x:y;
}

inline char max(char x,char y)
{
    return x>y?x:y;
}
