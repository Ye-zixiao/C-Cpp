#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace::std;

template<typename seq>
ostream& print(const seq& iseq, ostream& os = cout);

int main(void)
{
	vector<int> ivec;
	for (decltype(ivec)::size_type i = 0; i < 5; ++i)
	{
		ivec.push_back(i); ivec.push_back(i);
	}
	print(ivec) << endl;

	sort(ivec.begin(), ivec.end());
	print(ivec) << endl;

	auto unique_end_iter = unique(ivec.begin(), ivec.end());
	print(ivec) << endl;
	ivec.erase(unique_end_iter, ivec.end());
	print(ivec) << endl;

	return 0;
}


/*
CPU��amd ����3600x        1449
�Կ���Ѷ��rx5700����GTX2060    2400����
�ڴ棺������LPXϵ�� 3200����֥��sniper X�ѻ���3200����֥��ù�ϵ��   16g700Ԫ
���壺΢��b450ս����������΢��b450m mortar�Ȼ��ڻ�����600~699                699
��̬����������C2000 Pro ���߶�֥RD500�����õĿ��������ǵ�970evo plus       ����1T900Ԫ/���ǵĻ�500G800Ԫ
��Դ����������GX550			400
ɢ����������TS120    200
���䣺����				300

*/
