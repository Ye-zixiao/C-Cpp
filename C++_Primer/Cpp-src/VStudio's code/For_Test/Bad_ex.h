#ifndef BAD_EX_H_
#define BAD_EX_H_

#include<iostream>

namespace second_bad_nsp {
	void bad_nsp_func(void) {
		std::cout << "bad namespace func()" << std::endl;
	}
}

using namespace::second_bad_nsp;//��ͷ�ļ���ֱ��ʹ��usingָʾ��һ�ֲ��õ���Ϊ


#endif


//#include"Bad_ex.h"
//#include"Bad_exa.h"
//
//int main(void)
//{
//	//bad_nsp_func();
//		/*����first_bad_nsp��second_bad_nsp�����ռ���ӵ��ͬ���ĺ�����
//		������ͷ�ļ���ֱ��ʹ��usingָʾ��ʹ�ð�����ͷ�ļ���������������ֳ�ͻ�����*/
//	first_bad_nsp::bad_nsp_func();//��ͨ����������������Ժܺõı�����������
//	second_bad_nsp::bad_nsp_func();
//
//	return 0;
//}