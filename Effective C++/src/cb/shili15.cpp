#include<iostream>
using namespace std;

class Test {
	double dvalue = 10.11;
public:
	Test(double d):dvalue(d+1.1){}
	//double& get(void)  { return dvalue; }//����ʹ����ֵ����get����
	double& get(void)& { return dvalue; }//������ʹ����ֵ����get����
};

int main(void)
{
	double& ref_double = Test(42.1).get();
	cout << ref_double << endl;

	return 0;
}
