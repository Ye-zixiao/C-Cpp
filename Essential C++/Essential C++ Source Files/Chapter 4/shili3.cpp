#include <iostream>
#include <string>

using namespace std;

class test
{
private:
    static int m_value;		    //����˽����ľ�̬��Ա����

public:
    test()
    {
    	m_value++;
    }

    static int getValue()		//������ľ�̬��Ա����
    {
    	return m_value;
    }
};

int test::m_value = 0;		    //��ľ�̬��Ա������Ҫ����������ڴ�ռ�

int main()
{
    test t1;
    test t2;
    test t3;

    cout << "test::m_value2 = " << test::getValue() << endl;	//ͨ������ֱ�ӵ��ù��о�̬��Ա��������ȡ�������
    cout << "t3.getValue() = " << t3.getValue() << endl;		//ͨ�����������þ�̬��Ա������ȡ�������

    return 0;
}
