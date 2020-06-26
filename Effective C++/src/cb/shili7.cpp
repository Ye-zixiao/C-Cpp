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

	//1��֤ͬ���ԣ�ֻ��֤�Ը�ֵ��ȫ
	/*Test& operator=(const Test& rhs) {
		if (this != &rhs) {
			delete pvalue;
			pvalue = new int(*rhs.pvalue);
		}
		return *this;
	}*/
	//2���ڿ���ǰ������ԭ���󣬶����ڿ����ɹ���������٣��쳣��ȫ
	/*Test& operator=(const Test& rhs) {
		int* pOrigin = pvalue;
		pvalue = new int(*rhs.pvalue);
		delete pOrigin;
		return *this;
	}*/
	//3�������������������쳣��ȫ
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
