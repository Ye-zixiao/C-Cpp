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
	havebase(havebase&&) = default;//��1��һ������ʽ����Ϊɾ�����ƶ����캯�����ں���ƥ���ʱ�򱻺���

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
	havebase(const havebase&)//havebase(havebase&&)=default;Ӧ���Ǳ�ɾ���ģ���������A defaulted move constructor that is defined as deleted
	hello world				// is inored by overload resolution  ��һ������ʽ=default��ɾ�����ƶ����캯���ᱻ����ƥ��������
	hello world
*/
