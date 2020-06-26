#include<iostream>
#include<typeinfo>
#include<string>
//#define DEBUG
using namespace std;

class Test {
public:
	Test(int value):
		pvalue(new int(value)){}
	Test(const Test&rhs):
		pvalue(new int(*rhs.pvalue)){}
	~Test(){
		if (pvalue){
#ifdef DEBUG
            cout<<"~Test()"<<endl;
#endif
            delete pvalue;
		}
	}

	//1、证同测试：只保证自赋值安全
	/*Test& operator=(const Test& rhs) {
		if (this != &rhs) {
			delete pvalue;
			pvalue = new int(*rhs.pvalue);
		}
		return *this;
	}*/
	//2、在拷贝前不销毁原对象，而是在拷贝成功后才再销毁：异常安全
	/*Test& operator=(const Test& rhs) {
		int* pOrigin = pvalue;
		pvalue = new int(*rhs.pvalue);
		delete pOrigin;
		return *this;
	}*/
	//3、拷贝并交换技术：异常安全
	Test& operator=(Test rhs) {
		rhs.swap(*this);
		return *this;
	}

	int get(void) { return pvalue ? *pvalue : -1; }
	void swap(Test& rhs) {
		int* ptemp = pvalue;
		pvalue = rhs.pvalue;
		rhs.pvalue = ptemp;
	}

private:
	int* pvalue = nullptr;
};


int main(int argc, char** argv)
{
	Test item(312);
	item = item;
	cout << item.get() << endl;
	return 0;
}
