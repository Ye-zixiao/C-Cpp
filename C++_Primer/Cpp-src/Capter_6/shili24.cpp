#include<iostream>
#include<string>
using namespace::std;

bool Bigger(const string& s1, const string& s2)//�ж��ַ�����ǰ�߳����Ƿ�Ⱥ��ߴ�
{
	return s1.size() >= s2.size();
}

//��һ�֣�ʹ��ָ�����ĺ���ָ��
const string& useBigger(const string& s1, const string& s2, bool (*pf)(const string&, const string&))
{
	if (pf(s1, s2))
		return s1;
	else return s2;
}

//�ڶ��֣��������͵��β��Զ�ת����ָ������ָ��
/*const string& useSmaller(const string& s1,const string& s2,bool func(const string&,const string&))
{
    if(!func(s1,s2))
        return s1;
    else return s2;
}
*/

//�����֣�ʹ�����ͱ���ʹ�ú���ָ��ı�д��Ϊ���
//using PFunc=bool (*)(const string&,const string&);
typedef bool (*PFunc)(const string&,const string &);
const string& useSmaller(const string &s1,const string& s2,PFunc pf)
{
    if(!pf(s1,s2))
        return s1;
    else return s2;
}

int main(void)
{
	//bool (*pf)(const string&, const string&) = Bigger;
	cout << useBigger("hello world", "show me the code", Bigger) << endl;
	cout << useSmaller("hello world","show me the code", Bigger) << endl;
	return 0;
}
