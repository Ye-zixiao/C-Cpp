#include<iostream>
#include<fstream>
#include<string>
using namespace::std;

void check_iostate(istream&is)
{
	if (is.bad())
		cout << "badb" << ' ';
	if (is.fail())
		cout << "fail" << ' ';
	if (is.eof())
		cout << "eof" << ' ';
	if (is.good())
		cout << "good" << ' ';
}

/*clear���������в�����ʱ�������þ��ǽ�������״̬��һ������״̬λ��
����Ļ��������Լ���ϣ��������������������״̬λ*/

int main(void)
{
	int value;

	cin.setstate(~cin.badbit | ~cin.failbit | ~cin.eofbit);
	check_iostate(cin);
	cout << endl;
	istream::iostate old_state = cin.rdstate();


	//���clear���÷�
	//cout << (cin.rdstate() & ~cin.failbit & ~cin.badbit) << endl;
	cin.clear(istream::eofbit);//set eofbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::badbit);//set badbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::failbit);//set failbit,clear other bits
	check_iostate(cin);
	cout << endl;

	cin.clear(istream::eofbit | istream::failbit);//set failbit and eofbit,clear other bits
	check_iostate(cin);
	cout << endl;

	return 0;
}
