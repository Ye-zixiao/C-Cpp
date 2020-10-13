#include <iostream>

class A {//4+4
public:
	virtual void afunc() const {
		//
	}

private:
	int avalue;
};

class B {//8
public:
	virtual void bfunc() const {
		//
	}

private:
	int bvalue;
};


/** 
 * 若是采用虚基类指针策略，则为8+8+4+4+4+4=32
 * 若是采用虚基类指针表策略，则为8+8+4+4+4=28
 * 若是采用虚函数指针表存储虚基类，则为8+8+8=24
 */
class C :public virtual A, public virtual B {
public:
	virtual void cfunc() const {
		//
	}

private:
	int cvalue;
};

int main(void)
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(C) << std::endl;
	return 0;
}