/*
 *1���ڲ��������������ͬ������
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value){}
void test(void) {
	using nsp::func;//nsp::func����������func����
	func(12);
}


/*
 *2��ֱ�ӷ������ֳ�ͻ
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value){}
using nsp::func;

int main(void)
{
	func(21);
	return 0;
}

/*
 *3��using����ͬ������ͬ�β��б��ᱻ��Ϊ�����ֳ�ͻ����������
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(void){}
using nsp::func;
//��ʹ��using������ͬһ����������ͬ������ͬ�β��б�Ͳ��ᷢ�����ֳ�ͻ

int main(void)
{
	func();
	return 0;
}


/*
 *4.1��usingָʾʹ�������ռ��е�����ע�뵽�����������������ֳ�ͻ
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value) {}
void test(void) {
	using namespace::nsp;
	func(2);
	/*ֱ�ӷ������ֳ�ͻ����Ϊusingָʾ��nsp�����ռ��е�func����ע�뵽�˵�ǰ���������������
	����nsp�����ռ��е�����������������е�����ͬ����ͬ�β��б���ᷢ�����ֳ�ͻ*/
}


/*
 *4.2��������ͬ������
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value) {}
using namespace::nsp;
