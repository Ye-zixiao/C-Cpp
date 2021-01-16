#include"UserProfile.h"

int main(void)
{
	UserProfile anon;
	cout << anon;
	UserProfile anon_too;							//试验默认id编号方式
	cout << anon_too;

	UserProfile anna("Annal", UserProfile::Guru);	//指定用户初始化数据
	cout << anna;
	anna.bump_guess_count(27);						//给用户数据增值
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	cout << anna;

	cin >> anon;									//通过输入重新给用户输入参数
	cout << anon;

	return 0;
}
