#include<iostream>

extern "C" {
#include"externC.h"
}
extern "C" void (*pf)(int) = func;//pf是一个指向C函数的函数指针
extern "C" typedef void FC(int);//FC是一个C函数的函数类型别名
extern "C" using pCfunc = void (*)(int);//pCfunc是一个指向C函数的函数指针的别名

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
