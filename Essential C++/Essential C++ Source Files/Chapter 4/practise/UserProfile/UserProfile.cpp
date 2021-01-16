#include"UserProfile.h"

map<string, UserProfile::uLevel> UserProfile::_level_map;

void UserProfile::init_level_map()
{
	_level_map["Beginner"] = Beginner;
	_level_map["Intermadiate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

ostream& operator<<(ostream& os, const UserProfile& rhs)			/*使用形式是：os<<rhs  （前者是参数1：输出流，
																	后者是参数2：指定的类对象）
																		它会将类对象类对象中的数据输出到相应输出流中*/
{
	os << rhs.login() << ' '
		<< rhs.level() << ' '
		<< rhs.login_count()<< ' '
		<< rhs.guess_count() << ' '
		<< rhs.guess_correct() << ' '
		<< rhs.guess_average() << endl;
	return os;
}

istream& operator>>(istream& is, UserProfile& rhs)
{
	string login, level;
	is >> login >> level;

	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;
	rhs.reset_login(login);
	rhs.reset_level(level);

	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.reset_guess_correct(gcorrect);

	return is;
}
