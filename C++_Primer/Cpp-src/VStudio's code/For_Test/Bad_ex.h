#ifndef BAD_EX_H_
#define BAD_EX_H_

#include<iostream>

namespace second_bad_nsp {
	void bad_nsp_func(void) {
		std::cout << "bad namespace func()" << std::endl;
	}
}

using namespace::second_bad_nsp;//在头文件中直接使用using指示是一种不好的行为


#endif


//#include"Bad_ex.h"
//#include"Bad_exa.h"
//
//int main(void)
//{
//	//bad_nsp_func();
//		/*由于first_bad_nsp和second_bad_nsp命名空间中拥有同名的函数，
//		导致在头文件中直接使用using指示会使得包含该头文件的作用域出现名字冲突的情况*/
//	first_bad_nsp::bad_nsp_func();//而通过作用域运算符可以很好的避免这种问题
//	second_bad_nsp::bad_nsp_func();
//
//	return 0;
//}