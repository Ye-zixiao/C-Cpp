#include<iostream>
#include<string>
#include<utility>
using std::cout;
using std::endl;
using std::string;

class X {
public:
	X(int v):value(v){
		//cout << "X(int v)" << endl;
	}

	//X(X&& item)noexcept ://Move Constructor
	//	value(std::move(item.value)) {
	//	item.value = 0;
	//	cout << "X(X&&item)" << endl;
	//}

	X(const X& item) ://Copy Constructor
		value(item.value) {
		cout << "X(const X&item)" << endl;
	}

private:
	int value;
};

class Y {
public:
	Y(int v) :value(v) {
		//cout << "Y(int v)" << endl;
	}

	Y(Y&& item)noexcept ://Move Constructor
		value(std::move(item.value)) {
		item.value = 0;
		cout << "Y(Y&&item)" << endl;
	}

	//Y(const Y& item) ://Copy Constructor
	//	value(item.value) {
	//	cout << "Y(const X&item)" << endl;
	//}

private:
	int value;
};


class hasX {
public:
	hasX(int v):x(v),y(v){}

	hasX(hasX&&) = default;

private:
	X x;
	Y y;
};

hasX fuc(void) {
    #include<iostream>
#include<string>
#include<utility>
using std::cout;
using std::endl;
using std::string;

class X {
public:
	X(int v):value(v){
		//cout << "X(int v)" << endl;
	}

	//X(X&& item)noexcept ://Move Constructor
	//	value(std::move(item.value)) {
	//	item.value = 0;
	//	cout << "X(X&&item)" << endl;
	//}

	X(const X& item) ://Copy Constructor
		value(item.value) {
		cout << "X(const X&item)" << endl;
	}

private:
	int value;
};

class Y {
public:
	Y(int v) :value(v) {
		//cout << "Y(int v)" << endl;
	}

	Y(Y&& item)noexcept ://Move Constructor
		value(std::move(item.value)) {
		item.value = 0;
		cout << "Y(Y&&item)" << endl;
	}

	//Y(const Y& item) ://Copy Constructor
	//	value(item.value) {
	//	cout << "Y(const X&item)" << endl;
	//}

private:
	int value;
};


class hasX {
public:
	hasX(int v):x(v),y(v){}

	hasX(hasX&&) = default;

private:
	X x;
	Y y;
};

hasX fuc(void) {
    hasX test(10);
    return test;
}

int main(void)
{
	hasX test(1), test_move = fuc();
	//hasX test_cpy = test;

	return 0;
}
	return
}

int main(void)
{
	hasX test(1), test_move = fuc();
	//hasX test_cpy = test;

	return 0;
}
