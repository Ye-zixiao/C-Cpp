#ifndef BAD_EXA_H_
#define BAD_EXA_H_

#include<iostream>

namespace first_bad_nsp {
	void bad_nsp_func(void) {
		std::cout << "bad_bad_func()" << std::endl;
	}
}

using namespace::first_bad_nsp;
//在头文件中是一种不好的行为，最多只能在头文件中的函数或者命名空间内使用using指示


#endif