#include <iostream>
#include <typeinfo>

class Base{
public:
	virtual void func() const = 0 {
		std::cout<<std::endl;
	}
};

class Derived:public Base{
public:
	void func() const override{
		Base::func();
		std::cout<<"fuck"<<std::endl;
	}
};


int main(void)
{
	Derived item;
	item.func();
	return 0;
}