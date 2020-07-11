#include<iostream>
using namespace std;

class Test {
	double dvalue = 10.11;
public:
	Test(double d):dvalue(d+1.1){}
	//double& get(void)  { return dvalue; }//可以使得右值调用get函数
	double& get(void)& { return dvalue; }//不可以使得右值调用get函数
};

int main(void)
{
	double& ref_double = Test(42.1).get();
	cout << ref_double << endl;

	return 0;
}
