#include <iostream>
#include <cstdio>

class Test{
public:
    virtual ~Test(){}

    float x(){return _x;}
    float y(){return _y;}
    virtual float z(){return _z;}

private:
    float _x,_y,_z;
};

int main(void)
{
    printf("%p\n",&Test::x);
    printf("%p\n",&Test::y);
    // printf("%p\n",&Test::~Test);
    printf("%p\n",&Test::z);
    return 0;
}