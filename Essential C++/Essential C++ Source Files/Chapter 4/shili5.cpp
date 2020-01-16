#include<iostream>
#include<vector>
using namespace std;

class num_sequence
{
public://�����ӿ�
	typedef void (num_sequence::*PtrType)(int);	//������һ����Ա����ָ��

	void fibonacci(int pos);					//���������㷨��������������е�ֵȻ�����ŵ���̬��Ա����vector֮��
	void pell(int pos);
	void lucas(int pos);
	void triangular(int pos);
	void sequare(int pos);
	void pentagonal(int pos);

	int elem(int pos);							//�������е�ĳһ��λ���ϵ�ֵ
	bool check_integrity(int pos);              //���λ���Ƿ�����������Ч

private:
	vector<int>* _elem;							//��Ű���ָ���о������е�vector������ָ��
	PtrType _pmf;
	static const int num_seq = 7;
	static PtrType func_tbl[num_seq];
	static vector<vector<int> > seq;
};

/*���ھ�̬����������Ϊ�����������ʱ��*/
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);

num_sequence::PtrType num_sequence::func_tbl[num_seq] =	/*1������PtrType��num_sequence���Ƕ�����ͣ���������������Ա����ָ��
														���з���ʱ����������ǰ�������������������������ơ�
														  2���������num_sequence::func_tbl[num_seq]ǰ�����num_sequence::��֮��ͬ��
														��Ŀ����Ϊ�˱����þ�̬��Ա���������ݣ���������һ�����*/
{
	0,
	&num_sequence::fibonacci,
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::pentagonal,
	&num_sequence::sequare,
};


int main(void)
{
	num_sequence ns;
	num_sequence* pns = &ns;
	num_sequence::PtrType pm = &num_sequence::fibonacci;
	int pos = 9;
	(ns.*pm)(pos);			/*��Ա����ָ��Ľ����õ���Ա����ʹ��ʱû������ͨ����ָ�������������÷�����ʽ����1������ʽ��
								2����ָ�뺯�����ʽ������������ʷԭ����ɵģ�*/
	(pns->*pm)(pos);


	return 0;
}

int num_sequence::
elem(int pos)
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elem->size())
		(this->*_pmf)(pos);

	return (*_elem)[pos - 1];
}
