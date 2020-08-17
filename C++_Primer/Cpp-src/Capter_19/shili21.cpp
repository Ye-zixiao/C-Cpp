#include<iostream>
#include<string>
using namespace::std;

class Screen {
public:
	using pos = string::size_type;
	Screen(const string&s,int c,int h,int w):
		contents(s),cursor(c),height(h),width(w){}

	static const string Screen::* get_pstr(void) {
		return &Screen::contents;
	}

private:
	string contents;
	pos cursor;
	pos height, width;
};

int main(void)
{
	Screen item("hello world", 0, 1, 2);
	const string Screen::* pstr = Screen::get_pstr();
	cout << item.*pstr << endl;

	return 0;
}
