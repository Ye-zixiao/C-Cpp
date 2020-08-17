#include<iostream>
#include<utility>
using namespace::std;

class Base {
public:
	Base() = default;
	Base(const Base&item):
		value(item.value){
		cout << "Base(const Base&)" << endl;
	}
	Base(Base&&) = delete;

private:
	int value = 0;
};

class haveBase {
public:
	haveBase() = default;
	//haveBase(const haveBase&)
	haveBase(const haveBase&) = default;
	haveBase(haveBase&&) = default;

private:
	Base i;
};

int main(void)
{
	haveBase item;
	haveBase item_mv = std::move(item);

	return 0;
}
