#include<iostream>
#include<string>

class Test {
	std::string str;
public:
	Test(const std::string&s):str(s){}

	std::string& get(void) {
		return str;
	}
};

int main(void)
{
	Test item("hello world");
	std::string& (Test:: * pcf)(void) = &Test::get;
	//�ȼ���(item.(Test::get))(),�ڵȼ���(item.get)(),���ȼ���item.get()
	(item.*pcf)() = "hello china";
	std::cout << item.get() << std::endl;

	return 0;
}
