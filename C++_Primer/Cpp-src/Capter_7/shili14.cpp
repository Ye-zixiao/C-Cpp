#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Screen;
/*3��������Ԫ������������Ȼ��ʹ�õ�Ƕ����Ԫ��������֣����Ա�������Ԫ������������֮ǰ����Ƕ
����Ԫ�������࣬��ʱ�����Screen���ǲ���ȫ���ͣ��ʵ�������Ԫ������������Windows_mgr���ܴ���
Ƕ����Ԫ���������ʵ�壬�����Դ�������������ص����û���ָ�룬�Լ��β���Ҫ�漰��Screen���ʵ
��Ͳ�Ҫ�������Ķ���������ڲ�*/

class Windows_mgr {
public:
	using ScreenIndex = string::size_type;

	void clear(ScreenIndex i);
	/*2��������Ԫ����һ������Ƕ����Ԫ����Screen��˽�г�Ա��������Ԫ����
	ֻ������Ԫ��������Windows_mgr�����������ܶ�����Ԫ��������Ϊ��Ԫ����һ
	��ط���Screen���е�˽�г�Ա���������Screen�е�ʵ�����Ȼ���ڴ˴���
	���������Ͳ�֪��Ƕ����Ԫ����Ķ������֪��������ʲô���ݳ�Ա��������Ԫ
	����ֻ������Ԫ�������������������ܶ���*/
	void push_back(const Screen& item);
	ostream& display(ostream& os)const;
private:
	vector<Screen> screens;
};

class Screen {
	friend void Windows_mgr::clear(ScreenIndex i);
	/*1����Ϊ��Ԫ��������Ҫ����Ԫ����֮ǰ�ͱ�������������Ԫ������������
	����������������ֻ�п��ܣ���Ԫ��������Windows_mgr�Ķ���������Ƕ��
	��Ԫ����Screen�Ķ���֮ǰ*/

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
/*4����Ԫ�����Ķ������Ƕ����Ԫ��������Ķ���ĺ��棬
������Ԫ�����Ϳɼ�Ƕ����Ԫ��������ľ����Ա��������Ҳ�Ͳ��ᱨ��*/
{
	if (i >= screens.size())
	{
		cout << "Out of range!" << endl;
		return;
	}
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
	//���ڵ�Screen��û�и�ֵ��صĳ�Ա���������Կ���ת��string�ĸ�ֵ������ʵ��
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
