#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

/*����1��ʹ��<��ͳ��ά���ڲ����б��>�ķ���������ָ�������ָ�����ָ�����������*/
const string(&function(const string(&ref_str_arr)[3]))[3]
{
	return ref_str_arr;
}

const string(*function(const string(*pstr_2d)[3]))[3]//��ͳ�Ľ�Ϊ���ӵķ���ָ�������ָ��ĺ���д����
//��Ҫ��һ��д��ָ��ָ��������ά�ȣ�ͬ����ں������β�Ҳ����ôҪ���
{
	return pstr_2d;
}

/*����2��ʹ��β�÷������ͷ����Ƚϼ򵥵ı�������ָ������*/
//auto function(const string(*pstr_2d)[3])->const string(*)[3]
//{
//	return pstr_2d;
//}

/*����3��ʹ��using����typedef�����������д��*/
//using strarr = const string[3];
//
//strarr* function(const string(*pstr_2d)[3])
//{
//	return pstr_2d;
//}

//������ʹ��decltype�ؼ�����ָ���������ͣ���Ϊdecltypeʹ�õ�ǰ����������붨����decltype��ǰ�棬
//decltype�����ж���������ͣ��ںܶ�����·����е㼦��

int main(void)
{
	string strarr[3] = { "hello","world","china" };
	for (unsigned i = 0; i != 3; ++i)
		cout << function(strarr)[i] << ' ';
	cout << endl;

	cout << "===============================" << endl;
	string strarr_2d[3][3]{ "hello","world","china","america",
		"japan","korean","nipen","show","code" };
	for (unsigned i = 0; i != 3; ++i)
	{
		for (unsigned j = 0; j != 3; ++j)
			cout << *(*(function(strarr_2d) + i) + j) << ' ';
		cout << endl;
	}

	return 0;
}
