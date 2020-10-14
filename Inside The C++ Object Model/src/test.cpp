#include <iostream>

class Test{
public:
    Test(int val):
        value(val){}

    int func(void) {
        return value;
    }

    static int sfunc(){
        return svalue;
    }
private:
    int value;
    static int svalue;
};

int Test::svalue=10;

int main(void)
{  
    std::cout<<((Test*)0)->sfunc()<<std::endl;

    return 0;
}