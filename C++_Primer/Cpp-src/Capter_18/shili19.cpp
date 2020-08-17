#include<iostream>
#include<string>
using namespace::std;

class Class {};

class Base :public Class {
public:
	Base() = default;
	Base(const Base&) = default;
	//Base(int v):
	//	value(v){}//对Class基类调用默认构造函数
	//上面的额Base(int)也可以写成如下的形式：
	Base(int v):
		Class(),value(v){}//因为有些基类的部分使用默认的就可以了，不影响实际的初始化

private:
	int value;
};

class D1 :public virtual Base {
public:
	D1() = default;
	D1(const D1&) = default;
	D1(int v):Base(v){}
};

class D2 :public virtual Base {
public:
	D2() = default;
	D2(const D2&) = default;
	D2(int v) :Base(v){}
};

class MI :public D1, public D2 {
public:
	MI() = default;
	MI(const MI&) = default;
	MI(int v):
		Base(v),D1(v),D2(v){}
};

class Final :public MI, public Class {
public:
	Final() = default;
	Final(const Final&) = default;
	Final(int v):
		Base(v),MI(v),Class(){}
	//这个Class理论上不加进去其实也没有关系，但为了顺应含有虚基类的派生类对象的初始化（构造函数）的规则，还是加进去会比较清晰明了
};

int main(void) {
	Final item(10);
	return 0;
}
