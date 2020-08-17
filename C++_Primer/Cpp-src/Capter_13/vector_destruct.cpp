#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace::std;

class Test {
public:
	Test(int val) :value(val) {
		cout << "1����Test(int val)" << endl;
	}
	Test() :value(0) {
		cout << "2����Test()" << endl;
	}
	Test(const Test& item) :value(item.value) {
		cout << "3����Test(const Test&item)" << item.value << endl;
	}
	Test& operator=(const Test& item) {
		value = item.value;
		cout << "4����Test& operator=(const Test&item)" << endl;
		return *this;
	}
	~Test() {
		cout << "5����~Test()" << value << endl;
	}


private:
	int value;
};

int main(void)
{
	Test v1(10);//1
	Test v2;//2
	cout << endl;

	vector<Test> tvec;
	cout << tvec.capacity() << endl;
	tvec.push_back(v1);
	cout << tvec.capacity() << endl;
	tvec.push_back(v2);
	cout << tvec.capacity() << endl;
	tvec.push_back(32);
	cout << tvec.capacity() << endl;
	//vector<Test> tvec{ v1,v2,32 };//33 1333555
	/*ʹ���б��ʼ������������Ĵ�ӡ���33 1333555����֪��ִ�и����ʱvector�����ڴ��з���������Test��С��
	�ڴ浥Ԫ��Ȼ��ʹ�ÿ�����ʼ����ʼ֮������֮�����������һ��32��ʹ��ת������֮��׼��������ʼ��vector�е�
	Ԫ�أ����������ڴ���ֻ�����������ڴ浥Ԫ����󲻵ò����·��䶯̬�ڴ棬��������������ھ����˿�����ʼ��+
	�����Ĺ���
	*/

	cout << endl;
	return 0;//5*5
}

/*
��������
1����Test(int val)
2����Test()

//1����һ����ʼtvec��û��Ԫ�أ�push_back��ͬͨ�����ڴ��з����һ�鶯̬�ڴ��СΪ1��Test��ʹ�ÿ�����ʼ���������
0
3����Test(const Test & item)10
1

//2�����ڴ�ʱ��Ҫ���Ԫ�أ��������е�capacityΪ1����vector�������ֲ��ģ�������tvec���ڷ����СΪ2��Test��������
ʹ����ǰ��Ԫ�غ�����Test�ÿ�����ʼ���ķ�ʽ��ʼ��2�����󣬵����Ὣԭ���Ķ�̬�ڴ��ͷŵ����������һ����������ִ��
3����Test(const Test & item)0
3����Test(const Test & item)10
5����~Test()10
2

//3���ڵ�����push_back�У����������е�ʵ�β���Test���ͣ�������Ҫͨ��ת�����촴����һ����ʱTest����󡣵���������
�����е�capacity̫С����vector�������ֲ��ģ���������Ҫ���·��䶯̬�ڴ棬�������õ���3�ο�����ʼ������������һ����
��ʱTest����󿽱���ʼ������һ���ڴ�鵼�µġ������е�Ԫ�ض�����ת����ϣ�vector�ͻ��ͷ�֮ǰ��2���ڴ�飬����������
2����������ִ�У�����һ���������������ת������ʱ��������ʱ����ģ�
1����Test(int val)
3����Test(const Test & item)32
3����Test(const Test & item)10
3����Test(const Test & item)0
5����~Test()10
5����~Test()0
5����~Test()32
3

5����~Test()10
5����~Test()0
5����~Test()32
5����~Test()0
5����~Test()10

*/
