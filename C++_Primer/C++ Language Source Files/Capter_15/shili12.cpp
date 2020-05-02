#include<iostream>
#include<string>
#include<utility>
using namespace::std;

struct base {
	base() = default;
	base(const string& s) :
		str(s) {}

	base(const base&item):
		str(item.str){
		cout << "base(const base&)" << endl;
	}
	base(base&&) = delete;
	//~base() = default;

	string str;
};

struct havebase {
	havebase() = default;
	havebase(const string& s) :
		mem(s) {}

	havebase(const havebase& item) :
		mem(item.mem) {
		cout << "havebase(const havebase&)" << endl;
	}
	havebase(havebase&&) = default;//（1）一个被显式定义为删除的移动构造函数会在函数匹配的时候被忽略

	base mem;
};

int main(void)
{
	havebase item("hello world"), item_mv = std::move(item);
	cout << item_mv.mem.str << endl;
	cout << item.mem.str << endl;

	return 0;
}

/*
result:
	base(const base&)
	havebase(const havebase&)//havebase(havebase&&)=default;应该是被删除的，但是由于A defaulted move constructor that is defined as deleted
	hello world				// is inored by overload resolution  即一个因显式=default被删除的移动构造函数会被函数匹配所忽略
	hello world
*/
