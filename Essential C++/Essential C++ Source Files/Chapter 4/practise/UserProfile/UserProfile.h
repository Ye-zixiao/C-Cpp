#ifndef USERPROFILE_H_INCLUDED
#define USERPROFILE_H_INCLUDED

#include<iostream>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;

class UserProfile
{
public:
	enum uLevel{Beginner,Intermediate,Advanced,Guru};			//枚举类型，表示用户等级

	UserProfile(string login, uLevel = Beginner);				//构造函数
	UserProfile();

	bool operator==(const UserProfile& rhs);					//运算符重载
	bool operator!=(const UserProfile& rhs);

	/*-------读取用户数据------------*/
	string login() const { return _login; }
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	/*-------设置用户数据-----------*/
	void reset_login(const string& val) { _login = val; }
	void user_name(const string& val) { _user_name = val; }

	void reset_level(const string&);										//直接输入等级字符设置
	void reset_level(uLevel newlevel) { _user_level = newlevel; }			//输入枚举类型设置用户等级

	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }

	void bump_login_count(int cnt = 1) { _times_logged += cnt; }			//给用户数据增加数量，而不是重新设置
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }					//默认增加1
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;								//登录名称
	string _user_name;							//用户名
	int _times_logged;							//登录次数
	int _guesses;								//用户猜测次数
	int _correct_guesses;						//用户猜对次数
	uLevel _user_level;							//用户等级

	static map<string, uLevel> _level_map;		//静态map容器，里面放了形容用户等级的字符串对应枚举类型的字典集合
	static void init_level_map();				//初始化map容器的静态成员函数（方法）
	//static string guest_login();

};

ostream& operator<<(ostream& os, const UserProfile& rhs);
istream& operator>>(istream& is, UserProfile& rhs);

inline UserProfile::
UserProfile(string login, uLevel level)						//构造函数1：指定参数设置新用户
	:_login(login), _user_level(level),
	_times_logged(1), _guesses(0), _correct_guesses(0)
{}

inline UserProfile::
UserProfile()												//构造函数2：函数默认设置。会为用户设置一个独一无二的会话标识符id
	: _login("guest"), _user_level(Beginner),
	_times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;
	char buffer[16];
	_itoa(id++, buffer, 10);								//_itoa(a,b,c)函数会将a整数转化为相应的ASCII字符串（c进制形式）放到b中
	_login += buffer;										//将用户默认登录名称guest与表示符id拼接
}

inline double UserProfile::
guess_average() const
{
	return _guesses
		? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

inline bool UserProfile::
operator==(const UserProfile& rhs)
{
	if (_login == rhs._login && _user_name == rhs._user_name)
		return true;
	else
		false;
}

inline bool UserProfile::
operator!=(const UserProfile& rhs) { return !(*this == rhs); }

inline string UserProfile::
level() const
{
	static string _level_table[] = {
		"Beginner","Intermediate","Advanced",
		"Guru"
	};
	return _level_table[_user_level];				//根据枚举类型，从静态数组中返回相应字符串
}

inline void UserProfile::
reset_level(const string& level)
{
	map<string, uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	_user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
		//如果输入的level数据在map中找到，那么就设_user_level为相应的枚举类型（其实就是一个数字），否则的话就设为beginner（即0）
}

#endif // USERPROFILE_H_INCLUDED
