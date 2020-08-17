#include<iostream>
#include<string>
using namespace::std;

class Test {
public:
	Test() = default;
	Test(const string&str):sayings(str),value(4){}
	Test(const string &str,int val):sayings(str),value(val){}

	int get_value(void)const { return value; }
	string get_string(void)const { return sayings; }
	const Test& add(const Test& item)
	{
		sayings += item.sayings;
		value += item.value;
		return *this;
	}

private:
	string sayings;
	int value;
};

int main(void)
{
	Test test("test", 4);
	//cout << test.add("hello world").get_string() << endl;
	cout << test.add(static_cast<string>(" hello world")).get_string() << endl;
	//ʹ����ʽ�ؽ���hello world��ת����string����֮��ʹ��Test���ת�����캯����������ʱTest������ṩ��add���β�ʹ��

	return 0;
}
