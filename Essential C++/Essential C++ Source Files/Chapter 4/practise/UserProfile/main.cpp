#include"UserProfile.h"

int main(void)
{
	UserProfile anon;
	cout << anon;
	UserProfile anon_too;							//����Ĭ��id��ŷ�ʽ
	cout << anon_too;

	UserProfile anna("Annal", UserProfile::Guru);	//ָ���û���ʼ������
	cout << anna;
	anna.bump_guess_count(27);						//���û�������ֵ
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	cout << anna;

	cin >> anon;									//ͨ���������¸��û��������
	cout << anon;

	return 0;
}
