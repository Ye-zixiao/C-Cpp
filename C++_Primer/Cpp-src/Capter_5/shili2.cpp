#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	const vector<string> scores{ "F","D","C","B","A","A++" };
	unsigned grade;
	string lettergrade;
	cin >> grade;

	/*
	*ʹ������������ﵽ��if-else��ͬ��Ч��
	*/
	lettergrade = grade < 60 ? scores[0] :
		(grade == 100) ? (scores[(grade - 50) / 10]) :
		(grade % 10)>7 ? (scores[(grade - 50) / 10] + '+') :
		(grade % 10) < 3 ? (scores[(grade - 50) / 10] + '-') : scores[(grade - 50) / 10];
	cout << lettergrade << endl;

	return 0;
}

//ͬ���Ĵ��룬��Ϊͨ�׵Ŀ���ʹ�����µķ�ʽ��д��
/*
#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	const vector<string> scores{ "F","D","C","B","A","A++" };
	unsigned grade;
	string lettergrade;
	while (cin >> grade)
	{
		if (grade > 100)
			break;
		lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
		lettergrade += (grade == 100 || grade < 60) ? "" : (grade%10 < 3) ? "-" : (grade%10>7) ? "+" : "";
		cout << lettergrade << endl;
	}

	return 0;
}
*/
