#include<iostream>
using namespace::std;

struct B{};
struct D1:virtual B{};
struct D2:virtual B{};
struct D :D1, D2 {
	D():B(),D1(),D2(){}
};

struct D3 :D1, D2 {
	D3():D1(),D2(){}//�����Ļ���������B����ʽ��ִ��Ĭ�ϳ�ʼ��
};