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
	*使用条件运算符达到与if-else相同的效果
	*/
	lettergrade = grade < 60 ? scores[0] :
		(grade == 100) ? (scores[(grade - 50) / 10]) :
		(grade % 10)>7 ? (scores[(grade - 50) / 10] + '+') :
		(grade % 10) < 3 ? (scores[(grade - 50) / 10] + '-') : scores[(grade - 50) / 10];
	cout << lettergrade << endl;

	return 0;
}

//同样的代码，更为通俗的可以使用如下的方式编写：
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
