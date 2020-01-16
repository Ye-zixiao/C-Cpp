#include<iostream>
#include<vector>
using namespace std;

void show_seq(const vector<int> *seq);
const vector<int>* fibo_seq(int size);

int main(void)
{
	int size;
	cout << "Enter the seq_number of fibonacci: ";
	cin >> size;

	const vector<int>* pseq = 0;
	pseq = fibo_seq(size);
	if (pseq)
		show_seq(pseq);

	return 0;
}

void show_seq(const vector<int>* seq)
{
	for (int i = 0; i < (*seq).size(); i++)		//���������н����ã�����Ҫ������������֮������������������
		cout << (*seq)[i] << " ";				/*�����C�е�ָ��ṹ��ָ��Ľ���������ͬ�ģ�ֻ��������ΪC++�е�vector������
												�������ʲ�������ʷ���һ���á�->���������
												�����ԭ��"."����������ȼ����ڡ�->������������ȼ�*/
	cout << endl;
}

const vector<int>* fibo_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;				//ʹ�ú���������ľ�̬vector������������������й����ж����ᱻ�ͷ�

	if (size<0 || size>max_size)
	{
		cerr << "invalid size" << endl;
		return 0;
	}

	for (int i = elems.size(); i < size; i++)
	{
		if (0 == i || i == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[i - 1] + elems[i - 2]);
	}

	return &elems;
}
