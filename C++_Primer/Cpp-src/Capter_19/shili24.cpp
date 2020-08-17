#include<iostream>
#include<string>
using namespace::std;

class Screen {
	friend ostream& print(ostream&, const Screen&);
public:
	enum Directions {HOME,FORWARD,BACK,UP,DOWN};
	using Action = Screen & (Screen::*)(void);
	using size_type = size_t;

	Screen(size_type mh,size_type mw):
		max_height(mh),max_width(mw){}

	Screen& home(void) { height = width = 0; return *this; }
	Screen& up(void) {
		if (max_height != height)++height;
		return *this;
	}
	Screen& down(void) {
		if (0 != height)--height;
		return *this;
	}
	Screen& forward(void) {
		if (width != 0)--width;
		return *this;
	}
	Screen& back(void) {
		if (width != max_width)++width;
		return *this;
	}
	Screen& move(Directions cm) {
		return (this->*menu[cm])();
	}

private:
	const size_type max_height, max_width;
	size_type height = 0, width = 0;
	static Action menu[];
};

Screen::Action Screen::menu[] = {
	&Screen::home,&Screen::forward,
	&Screen::back,&Screen::up,&Screen::down
};

ostream& print(ostream& os, const Screen& sc) {
	for (Screen::size_type i = 0; i < sc.max_height; ++i) {
		for (Screen::size_type j = 0; j < sc.max_width; ++j)
			os << (i == sc.height && j == sc.width ? 'x' : '-');
		os << endl;
	}
	return os;
}

int main(void)
{
	Screen sc(6, 10);
	print(cout, sc) << endl;
	sc.move(Screen::BACK);
	sc.move(Screen::BACK);
	sc.move(Screen::UP);
	sc.move(Screen::UP);
	sc.move(Screen::BACK);
	print(cout, sc) << endl;

	return 0;
}
