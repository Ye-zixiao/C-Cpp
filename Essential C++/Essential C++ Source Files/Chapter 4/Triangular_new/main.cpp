#include"Triangular.h"


int main(void)
{
	Triangular tri1(20);
	Triangular tri2 = tri1;								//默认成员逐一赋值操作

	cout << "tri1:" << endl;	
	cout << tri1 << '\n';								//使用重载iostream（输出）运算符来输出类对象中的数据
		
	Triangular_iterator it = tri2.begin();
	Triangular_iterator end_it = tri2.end();

	cout << "Triangular Series 2 of " << tri2.length() << " elements\n";
	while (it != end_it)
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	cout << "Please enter the begin_pos and length for the new Triangular: ";
	Triangular tri_new;
	cin >> tri_new;
	cout << tri_new;

	return 0;
}