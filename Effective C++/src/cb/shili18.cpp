#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Base {
public:
	Base(T v) :value(v){}

	T getvalue(void) const {
		return value;
	}

	void modify(T new_value) {
		value = new_value;
	}

private:
	T value;
};

template<typename T>
class Derived :private Base<T> {
public:
	//using Base<T>::getvalue;
	Derived(T v,const string&s):
		Base<T>(v),str(s){}

	T getval(void) const {
		/*由于当一个派生类继承了一个模板化的基类时，编译器会默认的认为模板基类可能有特例化版本
		(而这个特例化版本可能具有与一般性模板不一样的接口)，出于这个不确定性，所以编译器在查找
		函数名字的时候不会到基类的作用域中查找相关的名字，除非我们用显式的this->,using声明等方
		式进行指出，否则编译无法通过*/
		return this->getvalue();//right
		//return Base<T>::getvalue();//right
		//return getvalue();//wrong

		//return getvalue();//使用上上面的using声明后，right
	}

	void modify_val(T new_val) {
		this->modify(new_val);
	}

	const string& getstr(void) const {
		return str;
	}

private:
	string str;
};

int main(void)
{
	Derived<int> item(342, "hello world");
	cout << item.getval() << item.getstr() << endl;

	return 0;
}
