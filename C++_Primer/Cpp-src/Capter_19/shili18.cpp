#include<iostream>
#include<typeinfo>
using namespace::std;

enum color {red,yellow,green,blue,black,white};
enum class flowers {beeflower,yellow_flower,blue_flower,red_flower};
enum country:unsigned {china,america,england,japan,korea,russia};

int main(void)
{
	auto choose = blue;
	cout << choose << endl;
	auto scoped_choose = flowers::blue_flower;

	color next_choose = color::white;
	cout << next_choose << endl;
	constexpr flowers item = flowers::yellow_flower;
	constexpr color my_color = color::yellow;
	cout << my_color << endl;

	cout << typeid(my_color).name() << endl;
	cout << typeid(item).name() << endl;

	auto value = country::china;
	cout << value << endl;

	return 0;
}
