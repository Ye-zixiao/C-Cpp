#include<iostream>

extern "C" {
#include"externC.h"
}
extern "C" void (*pf)(int) = func;//pf��һ��ָ��C�����ĺ���ָ��
extern "C" typedef void FC(int);//FC��һ��C�����ĺ������ͱ���
extern "C" using pCfunc = void (*)(int);//pCfunc��һ��ָ��C�����ĺ���ָ��ı���

void cppfunc(FC* fc) {
	fc(53);
}

void cppfunc2(pCfunc fc) {
	fc(452);
}

int main(void)
{
	cppfunc(func);
	cppfunc2(func);
	return 0;
}
