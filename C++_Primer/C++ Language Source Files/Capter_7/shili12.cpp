#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

class Screen {
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht,pos wd,char ch):
		height(ht),width(wd),contents(ht*wd,ch){}
	Screen(pos ht,pos wd):
		height(ht),width(wd),contents(ht*wd,' '){}

	char get(void) const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;//一般类中显式内联函数的关键字inline放在类外部
	Screen& move_cursor(pos ht, pos wd);
	Screen& set(char ch);
	Screen& set(pos row, pos col, char ch);
	Screen& display(std::ostream& os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os) const { do_display(os); return *this; }
	/*Screen move_cursor(pos ht, pos wd);
	Screen set(char ch);
	Screen set(pos row, pos col, char ch);
	Screen display(std::ostream& os) { do_display(os); return *this; }
	const Screen display(std::ostream& os) const { do_display(os); return *this; }*/

private:
	void do_display(std::ostream& os) const { os << contents; }
	//若do_display不是const成员函数，那么隐式的this指针将不能被一个指向const的指针初始化

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline char Screen::get(pos ht, pos wd) const
{
	if (ht * wd > (width - 1)* (height - 1))
		return '\0';
	return contents[ht * width + wd];
}

/*返回this所指的对象（的引用）*/
inline Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen& Screen::set(pos row, pos col, char ch)
{
	contents[row * width + col] = ch;
	return *this;
}

Screen& Screen::move_cursor(pos ht, pos wd)
{
	try {
		if (ht * wd > (height - 1)* (width - 1))
			throw std::runtime_error("Invalid position!");
		cursor = ht*width + wd;
		return *this;
	}
	catch (std::runtime_error err)
	{
		std::cout << err.what() << std::endl;
		return *this;
	}
}

/*返回this所指的对象的副本，而非this所指对象本身的引用*/
//inline Screen Screen::set(char ch)
//{
//	contents[cursor] = ch;
//	return *this;
//}
//
//inline Screen Screen::set(pos row, pos col, char ch)
//{
//	contents[row * width + col] = ch;
//	return *this;
//}
//
//Screen Screen::move_cursor(pos ht, pos wd)
//{
//	try {
//		if (ht * wd > (height - 1)* (width - 1))
//			throw std::runtime_error("Invalid position!");
//		cursor = ht*width + wd;
//		return *this;
//	}
//	catch (std::runtime_error err)
//	{
//		std::cout << err.what() << std::endl;
//		return *this;
//	}
//}

int main(void)
{
	Screen myScreen(5, 5, 'X');
	myScreen.move_cursor(4, 0).set('#').display(std::cout);
	std::cout << std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;

	return 0;
}
