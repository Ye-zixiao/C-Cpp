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
	//等价于(item.(Test::get))(),在等价于(item.get)(),及等价于item.get()
	(item.*pcf)() = "hello china";
	std::cout << item.get() << std::endl;

	return 0;
}
