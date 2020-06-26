#include<iostream>
#include<string>
#include<memory>
#include<tuple>
using namespace std;

class Date {
public:
	struct Day {
		explicit constexpr Day(int v):value(v){}
		int value;
	};
	struct Month {
		explicit constexpr Month(int v):value(v){}
		int value;
	};
	struct Year {
		explicit constexpr Year(int v):value(v){}
		int value;
	};

	static Month Jan() { return Month(1); }
	static Month Nov() { return Month(11); }

	Date(const Year&y,const Month&m,const Day&d):
		day(d),month(m),year(y){}

	tuple<Year, Month, Day> get(void) const {
		return tuple<Year,Month,Day>{ year,month,day };
	}

private:
	Day day;
	Year year;
	Month month;
};


int main(int argc, char** argv)
{
	Date date(Date::Year(1996), Date::Nov(), Date::Day(5));
	auto obj = date.get();
	cout << get<0>(obj).value << '-' << get<1>(obj).value << '-' << get<2>(obj).value << endl;

	return 0;
}
