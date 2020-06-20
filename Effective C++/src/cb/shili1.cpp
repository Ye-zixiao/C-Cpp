#include<iostream>
using namespace std;

class Test{
public:
    Test()=default;
    static constexpr int getscvalue(void){
        return scvalue;
    }

private:
    static constexpr int scvalue=42;//必须提供类内初始化器
};

constexpr int Test::scvalue;

int main(int argc,char**argv)
{
    Test item;
    cout<<item.getscvalue()<<endl;
    //cout<<Test::scvalue<<endl;

    return 0;
}
