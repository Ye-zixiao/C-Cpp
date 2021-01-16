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
CPU：amd 锐龙3600x        1449
显卡：讯景rx5700或者GTX2060    2400左右
内存：海盗船LPX系列 3200或者芝奇sniper X狙击者3200或者芝奇幻光系列   16g700元
主板：微星b450战斧导弹或者微星b450m mortar迫击炮基本上600~699                699
固态：海康威视C2000 Pro 或者东芝RD500，更好的可以用三星的970evo plus       海康1T900元/三星的话500G800元
电源：酷冷至尊GX550			400
散热器：利民TS120    200
机箱：随意				300

*/
