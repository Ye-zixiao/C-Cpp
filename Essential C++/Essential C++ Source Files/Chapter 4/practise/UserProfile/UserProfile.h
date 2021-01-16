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
	enum uLevel{Beginner,Intermediate,Advanced,Guru};			//ö�����ͣ���ʾ�û��ȼ�

	UserProfile(string login, uLevel = Beginner);				//���캯��
	UserProfile();

	bool operator==(const UserProfile& rhs);					//���������
	bool operator!=(const UserProfile& rhs);

	/*-------��ȡ�û�����------------*/
	string login() const { return _login; }
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	/*-------�����û�����-----------*/
	void reset_login(const string& val) { _login = val; }
	void user_name(const string& val) { _user_name = val; }

	void reset_level(const string&);										//ֱ������ȼ��ַ�����
	void reset_level(uLevel newlevel) { _user_level = newlevel; }			//����ö�����������û��ȼ�

	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }

	void bump_login_count(int cnt = 1) { _times_logged += cnt; }			//���û�����������������������������
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }					//Ĭ������1
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;								//��¼����
	string _user_name;							//�û���
	int _times_logged;							//��¼����
	int _guesses;								//�û��²����
	int _correct_guesses;						//�û��¶Դ���
	uLevel _user_level;							//�û��ȼ�

	static map<string, uLevel> _level_map;		//��̬map������������������û��ȼ����ַ�����Ӧö�����͵��ֵ伯��
	static void init_level_map();				//��ʼ��map�����ľ�̬��Ա������������
	//static string guest_login();

};

ostream& operator<<(ostream& os, const UserProfile& rhs);
istream& operator>>(istream& is, UserProfile& rhs);

inline UserProfile::
UserProfile(string login, uLevel level)						//���캯��1��ָ�������������û�
	:_login(login), _user_level(level),
	_times_logged(1), _guesses(0), _correct_guesses(0)
{}

inline UserProfile::
UserProfile()												//���캯��2������Ĭ�����á���Ϊ�û�����һ����һ�޶��ĻỰ��ʶ��id
	: _login("guest"), _user_level(Beginner),
	_times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;
	char buffer[16];
	_itoa(id++, buffer, 10);								//_itoa(a,b,c)�����Ὣa����ת��Ϊ��Ӧ��ASCII�ַ�����c������ʽ���ŵ�b��
	_login += buffer;										//���û�Ĭ�ϵ�¼����guest���ʾ��idƴ��
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
	return _level_table[_user_level];				//����ö�����ͣ��Ӿ�̬�����з�����Ӧ�ַ���
}

inline void UserProfile::
reset_level(const string& level)
{
	map<string, uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	_user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
		//��������level������map���ҵ�����ô����_user_levelΪ��Ӧ��ö�����ͣ���ʵ����һ�����֣�������Ļ�����Ϊbeginner����0��
}

#endif // USERPROFILE_H_INCLUDED
