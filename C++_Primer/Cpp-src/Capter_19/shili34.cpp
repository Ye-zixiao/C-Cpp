#include<iostream>
#include<string>
using namespace::std;

int globalvalue = 1000;


void func(void) {
	int localvalue = 1;
	class localClass {
		friend void func(void);
		//���ַ�ʽ��gcc������ʹ�ã�һ����˵һ�����Ѿ�����Ϊ�ֲ����ˣ���ôû�б�Ҫ��һЩ���ݳ�Ա����Ϊprivate
	public:
		int operator()(void) const {
			cout << "hello world" << endl;
			return 1;
		}
	private:
		int dd = globalvalue;
		//int tryfs = localvalue;
	};

	localClass f;
	int value = f();
	cout << f.dd << endl;
}

int main(void)
{
	func();
	return 0;
}
