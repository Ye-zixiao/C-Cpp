#include <iostream>
#include <string>

using namespace std;

class test
{
private:
    static int m_value1;		//����˽����ľ�̬��Ա����
public:
    static int m_value2;		//���幫����ľ�̬��Ա����

public:
    test()                      //���캯��
    {
    	m_value1++;
    	m_value2++;
    }

    int getValue()	            //���������ͨ��Ա����
    {
    	return m_value1;
    }

    /*static int get_static_value()
    {
        return m_value1;
    }*/
};

int test::m_value1 = 0;		//��ľ�̬��Ա������Ҫ����������ڴ�ռ�
int test::m_value2 = 0;		//��ľ�̬��Ա������Ҫ����������ڴ�ռ�

int main()
{
    test t1;
    test t2;
    test t3;

    cout << "test::m_value2 = " << test::m_value2 << endl;	//ͨ������ֱ�ӵ��ù��о�̬��Ա��������ȡ�������
    cout << "t3.m_value2 = " << t3.m_value2 << endl;		//ͨ��������ֱ�ӵ��ù��о�̬��Ա��������ȡ�������
    cout << "t3.getValue() = " << t3.getValue() << endl;	//ͨ��������������ͨ������ȡ�������
                                                                /*��ͨ��Ա�������Է��ʾ�̬��Ա������Ҳ���Է�����ͨ��Ա������
                                                                ����̬��Ա����ȴֻ���Է��ʾ�̬��Ա����*/
    //cout << "t3.m_value1= " << t3.m_value1 << endl;
    //cout << "t3.get_static_value= " << t3.get_static_value << endl;
    //cout << "test::m_value1 = " << test::m_value1 << endl;

    return 0;
}
