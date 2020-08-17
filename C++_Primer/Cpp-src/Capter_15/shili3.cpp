#include<iostream>
using namespace::std;

/*
1）public继承：
派生类的成员或者其友元可以访问基类中的public和protected成员，但是不能访问基类中的private成员，
而对于派生类用户（实例对象）只能访问基类中的public成员，对于它而言基类中的public还是public，，基类中的protected还是protected，基类中的private派生类没有继承也不能访问
2）private继承：
派生类的成员或者其友元可以访问基类中的public和protected成员，但是不能访问基类中的private成员，
对于派生类用户（实例对象）什么也不能访问，对于它而言基类中的public变成了private，基类中的protected变成了private，基类中的private它不能继承也不能访问
3）protected继承：
派生类的成员或者其友元可以访问基类中的public和protected成员，但是不能访问基类中的private成员，
对于派生类用户（实例对象）什么也不能访问，对于它而言基类中的public变成了protected，基类中的protected还是protected，基类中的private它没有继承也不能访问

- 基类中的访问说明符决定了派生类的成员能否访问基类的成员，其中派生类的成员和友元能够访问基类中的public和protected成员
- 派生列表中的访问说明符决定了派生类实例对象能否访问基类中的public成员，并且影响派生类的派生类的成员对其直接基类的成员访问权限
*/

class Base {
public:
	Base() = default;

	int pub_mem = 0;
protected:
	int pro_mem = 0;
private:
	int pri_mem = 0;
};

class Derived_pub :public Base {
public:
	Derived_pub():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_pri :private Base {
public:
	Derived_pri():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_pro :protected Base {
public:
	Derived_pro():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_from_Derived_pri :public Derived_pri {
public:
	Derived_from_Derived_pri():Derived_pri(){}

	void func(void) {
		//基类中的pub_mem和pro_mem对于Derived_from_Derived_pri类而言都变成了private的了
	}
};

class Derived_from_Derived_pro :public Derived_pro {
public:
	Derived_from_Derived_pro():Derived_pro(){}

	void func(void) {
		this->pro_mem;//此时基类中的pub_mem和pro_mem对于Derived_from_Derived_pro类而言都是protect成员
		this->pub_mem;
	}
};

int main(void)
{
	Base item;
	cout << item.pub_mem << endl;

	Derived_pub item_pub;
	cout << item_pub.pub_mem << endl;

	Derived_pri item_pri;
	//cout << item_pri.pub_mem << endl;

	Derived_pro item_pro;
	//cout << item_pro.pub_mem << endl;

	Derived_from_Derived_pri item_pri_pub;
	//cout << item_pri_pub.pub_mem << endl;

	Derived_from_Derived_pro item_pro_pub;
	//cout << item_pro_pub.pub_mem << endl;

	return 0;
}
