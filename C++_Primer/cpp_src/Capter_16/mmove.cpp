#include<iostream>
#include<vector>
#include<string>
#include<type_traits>
using namespace::std;

template<typename T>
auto mmove(T&& rvalue) ->typename remove_reference<T>::type&& {
	return static_cast<typename remove_reference<T>::type&&>(rvalue);
}

/*
1����mmove����ʵ����һ����ֵ��T�������ֵ���������ˣ�rvalue��һ����ֵ���õ���ֵ���ã����������۵��Ĺ������ᱻ�۵�Ϊһ����ֵ���ã�
	��ʱʹ��remove_reference��ȥ��T���������Ի����ֵ������ָ������ͣ���ͨ��static_cast��rvalue��ֵ����ǿ��ת��Ϊ��ֵ����
2����mmove����ʵ�α������һ����ֵ���򷵻صľ���һ����ֵ�������ر��ת��
*/

int main(void)
{
	string str = "hello world";
	string str_mv = mmove(str);
	//cout << str << ' ' << str_mv << endl;
	cout << str.size() << endl;
	cout << str_mv.size() << endl;

	return 0;
}
