#include<iostream>

class Test{
public:
    static Test& get_instance(void){
        static Test item(42);
        return item;
    }

    int get(void) const{
        return value;
    }

private:
    int value;
    Test(int v):value(v){}
};

int main(int argc,char** argv)
{
    Test& ref_test=Test::get_instance();
    std::cout<<ref_test.get()<<std::endl;

    return 0;
}
