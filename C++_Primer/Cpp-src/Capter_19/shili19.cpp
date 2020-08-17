#include<iostream>
using namespace::std;

enum class color :int {
	red,blue,yellow,black,
	orange,green,white
};

ostream& print_enum(ostream& os, color c) {
	switch (c) {
		case color::red:os << "red:"<<static_cast<int>(c);break;
		case color::white:os << "white:" <<static_cast<int>(c);break;
		case color::blue:os << "blue:" << static_cast<int>(c);break;
		case color::black:os << "black:" << static_cast<int>(c);break;
		case color::green:os << "green:" << static_cast<int>(c);break;
		case color::orange:os << "orange:" << static_cast<int>(c);break;
		default:break;
	}
	return os;
}

int main(void)
{
	auto my_choose = color::orange;
	print_enum(cout, my_choose)<<endl;

	return 0;
}
