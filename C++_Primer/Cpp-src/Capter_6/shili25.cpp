//����Ŀ�ģ���дһ������������һ������ָ�룬ֱ�ӷ��ظú���������
#include<iostream>
#include<string>
using namespace::std;

string strcat(const string& s1, const string& s2)
{
	return s1 + s2;
}

//��һ�֣�ʹ�����ͱ���
using PF = string(*)(const string&, const string&);
PF ret_pf1(PF pf)
{
	return pf;
}

//�ڶ��֣�ʹ��ֱ�ӱ�ʾ�������ַ�����Ϊ���ӵ㣩
//��������ret_pf2���ú�������һ������ָ��pf������һ������ָ�룬��������ָ����ָ��ĺ����������Ͷ���string�����յĲ���Ϊ����const string&
string (*ret_pf2(string(*pf)(const string&, const string&)))(const string&, const string&)
{
	return pf;
}

//�����֣�ʹ��β�÷������ͷ��������ֱ�ӷ����ܶ�
auto ret_pf3(string(*pf)(const string&, const string&))->string(*)(const string&, const string&)
{
	return pf;
}

int main(void)
{
	cout << strcat("hello ", "world") << endl;//1��ֱ�ӵ���
	cout << ret_pf1(strcat)("hello ", "world") << endl;//2��ʹ�����ͱ������򻯺���ָ��ı�д
	cout << ret_pf2(strcat)("hello ", "world") << endl;//3��ʹ��ֱ�ӷ�����д�ں�����ָ��ĺ�������Ϊ���ӣ�Ҳ���������
	cout << ret_pf3(strcat)("hello ", "world") << endl;//4��ʹ��β�÷������ͷ���д�ں�����ָ��ĺ����������ֱ�ӷ���Ϊ������Ҳ�������

	return 0;
}
