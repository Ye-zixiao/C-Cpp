#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::endl;

class X {//有移动操作
public:
	X(int val):value(val){}
	//X(const X& item) :
	//	value(item.value) {
	//	cout << "X(const X&)" << endl;
	//}
	X(X&& item)noexcept :
		value(std::move(item.value)) {
		cout << "X(X&&)" << endl;
		item.value = 0;
	}

	int get(void)const { return value; }

private:
	int value;
};

class Y {//没有移动操作，只有一个拷贝构造函数
public:
	Y(int val) :value(val) {}
	Y(const Y& item) :
		value(item.value) {
		cout << "Y(const Y&)" << endl;
	}

	int get(void)const { return value; }

private:
	int value;
};

class Test {
public:
	Test(int v1,int v2):x(v1),y(v2){}

	int getx(void)const {
		return x.get();
	}
	int gety(void)const {
		return y.get();
	}

private:
	X x;
	Y y;
};

Test fuc(void)
{
	return Test(33, 444);
}

int main(void)
{
	Test test(1, 2);
	//Test test_cpy = test;
	Test test_move = std::move(test);
	cout << "----" << endl;
	Test test_move_ = fuc();
	cout << "----" << endl;
	cout << test_move_.getx() << endl;
	cout << test_move_.gety() << endl;

	Y y(1), y_cpy = std::move(y);

	return 0;
}
