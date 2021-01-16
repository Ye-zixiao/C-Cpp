#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

template<typename elemtype>
void display(const list<elemtype>& a_list);

int main(void)
{
	list<string> a_list;
	a_list.push_back("hello world");
	a_list.push_back("niubiliaty");
	string svalue = "niubiliaty";

	list<string>::iterator it = find(a_list.begin(), a_list.end(), svalue);//�����Ҫalgorithmͷ�ļ�
	a_list.insert(it, 4, string("dummy"));
	display(a_list);

	/*it = a_list.begin();
	for (; it != a_list.end(); it++)
		cout << *it << endl;
*/
	return 0;
}

template<typename elemtype>
void display(const list<elemtype>& a_list)
{
	typename list<elemtype>::const_iterator it = a_list.begin();/*const_iterator����ָ���κε������е�Ԫ�أ�
                                                        ����iteratorֻ��ָ����ͨ�����е�Ԫ�أ�������ָ��
                                                        const�����е�Ԫ��*/

	for (; it != a_list.end(); it++)
		cout << *it << endl;
}
