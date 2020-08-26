#include<iostream>
#include<string>
#include<utility>
using namespace::std;

void print(int&& rvalue, int& change) {
	cout << rvalue << ' ' << ++change << endl;
}

template<typename T1, typename T2, typename Fuc>
void f(T1&& value1, T2&& value2, Fuc ff) {
	ff(value1, value2);
}

/*
1.1��������ʵ����һ����ֵ����ô����ģ��ĺ����βΣ�ԭ����һ��ָ����ģ�����Ͳ�������ֵ���ã����������۵������һ����ֵ���ã�
1.2��������ʵ����һ����ֵ����ô����ģ��ĺ����βξͻ���Ϊ�����۵��Ĺ�ϵ����������ֵ���õ�����

��������������ֵ���û�����ֵ���ö��Ǳ������䱾�ʶ�����ֵ���������뽫�����ֵ���ݸ��ڲ�ĺ����������ֺ���ʵ�Σ���ֵ����ֵ�����ԣ�����ô��Ҫ
ʹ��forwardת������

2.1����һ����ֵ���ý���forward������T���������ͣ���ôforward�᷵������������͵���ֵ���ã��ָ��������۵���ʱ���᷵��һ����ֵ���ã�����ֵ���õ����Լ������֣�
2.2����һ����ֵ���ý���forward�����ڴ�ʱ��T��һ����ͨ���ͣ���ôforward���������ֵ���õ��䱾������ֵ��forward�᷵��T����ֵ���ã��ʺ���ʵ�ε���ֵ�������Լ������֣�
����ʹ��forward��������ֵ���õı�������ֵ�����Ե��������ֵ������ͼ���ݸ��ڲ㺯������ͨ������ֵ�����β���Ȼ�ǲ��еģ���Ϊ��ͨ��ֵ�����޷��󶨵�һ����ֵ��

*/

template<typename T>
void infuc(T&& rvalue) {
	++rvalue;
}

template<typename T>
void func(T&& rvalue) {
	cout << rvalue << endl;
	infuc(rvalue);//��ʱrvalue�ǰ󶨵���ֵ���õ���ֵ���ã��ʻ�����ֵ����
	cout << rvalue << endl;
}


void rever(int&& rvalue, int& lvalue) {
	cout << rvalue << ' ' << ++lvalue << endl;
}

template<typename T1, typename T2, typename Fuc>
void testfunc(T1&& v1, T2&& v2, Fuc inf) {
	cout << v1 << ' ' << v2 << endl;
	rever(std::forward<T2>(v2), std::forward<T1>(v1));
}

int main(void)
{
	int lvalue = 1002;
	testfunc(lvalue, 43, rever);/*��ʱ�������β�v1����ֵ���ã������β�v2����ֵ���ã����β����߱����϶��Ǳ�����������ֵ
								*/

}
