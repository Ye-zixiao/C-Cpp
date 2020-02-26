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
	//使用显式地将“hello world”转换成string类型之后使用Test类地转换构造函数创建出临时Test类对象提供给add的形参使用

	return 0;
}
