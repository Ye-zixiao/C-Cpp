#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Screen;
/*3、由于友元函数的声明必然会使用到嵌入友元的类的名字，所以必须在友元函数所属的类之前声明嵌
入友元函数的类，此时这个类Screen就是不完全类型，故导致了友元函数所属的类Windows_mgr不能创建
嵌入友元函数的类的实体，但可以创建此类类型相关的引用或者指针，以及形参若要涉及到Screen类的实
体就不要将函数的定义放在类内部*/

class Windows_mgr {
public:
	using ScreenIndex = string::size_type;

	void clear(ScreenIndex i);
	/*2、由于友元函数一般会访问嵌入友元的类Screen的私有成员，所以友元函数
	只能在友元所属的类Windows_mgr中声明而不能定义友元函数，因为友元函数一
	般回访问Screen类中的私有成员，即会访问Screen中的实体对象。然而在此处编
	译器根本就不知道嵌入友元的类的定义更不知道类中有什么数据成员，所以友元
	函数只能在友元所属的类中声明而不能定义*/
	void push_back(const Screen& item);
	ostream& display(ostream& os)const;
private:
	vector<Screen> screens;
};

class Screen {
	friend void Windows_mgr::clear(ScreenIndex i);
	/*1、因为友元函数机制要求友元函数之前就被声明过，且友元函数声明不能
	在类外声明，所以只有可能：友元所属的类Windows_mgr的定义必须放在嵌入
	友元的类Screen的定义之前*/

public:
	using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char ch) :
		height(ht), width(wd), contents(ht* wd, ch) {}
	Screen(const Screen& item) :
		cursor(item.cursor), height(item.height), width(item.width),
		contents(item.contents) {}

	char get(void)const { return contents[cursor]; }
	bool inrange(pos row, pos col) const
	{
		if (row >= height || col >= width) return false; else return true;
	}
	char get(pos row, pos col) const;
	pos size(void) const;
	Screen& move_cursor(pos row, pos col);
	Screen& set(pos row, pos col, char ch);
	Screen& set(char ch) { contents[cursor] = ch; return *this; }
	ostream& display(ostream& os) { do_display(os); return os; }
	ostream& display(ostream& os) const { do_display(os); return os; }

private:
	void do_display(ostream& os)const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

char Screen::get(pos row, pos col) const
{
	if (!inrange(row, col))
		return '\0';
	return contents[row * width + col];
}

Screen::pos Screen::size(void) const
{
	return height * width;
}

Screen& Screen::move_cursor(pos row, pos col)
{
	if (!inrange(row, col))
	{
		cout << "Out of range!" << endl;
		return *this;
	}
	cursor = row * width + col;
	return *this;
}

Screen& Screen::set(pos row, pos col, char ch)
{
	if (!inrange(row, col))
	{
		cout << "Out of range!" << endl;
		return *this;
	}
	contents[row * width + col] = ch;
	return *this;
}

void Windows_mgr::clear(ScreenIndex i)
/*4、友元函数的定义放在嵌入友元函数的类的定义的后面，
这样友元函数就可见嵌入友元函数的类的具体成员，编译器也就不会报错*/
{
	if (i >= screens.size())
	{
		cout << "Out of range!" << endl;
		return;
	}
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
	//现在的Screen还没有赋值相关的成员函数，所以可以转由string的赋值操作来实现
}

void Windows_mgr::push_back(const Screen& item)
{
	screens.push_back(item);
}

ostream& Windows_mgr::display(ostream& os) const
{
	for (const auto& elem : screens)
		elem.display(os) << endl;
	return os;
}

int main(void)
{
	Screen myscreen(4, 4, '#');
	cout << "before:";
	myscreen.display(cout) << endl;
	cout << "after:";
	myscreen.set(3, 3, '$').display(cout) << endl;
	cout << "myscreen's size=" << myscreen.size() << endl;

	cout << endl;
	Screen second_screen(4, 5, '&');
	Windows_mgr win;
	win.push_back(myscreen);
	win.push_back(second_screen);
	win.display(cout) << endl;

	return 0;
}
