#include<string>
#include<iostream>
#include<bitset>
using namespace::std;

template<size_t N>
class Solution {
public:
	Solution(const string& str) :
		bv(str) {}

	Solution& update(size_t n, bool new_ans) {
		bv.set(n, new_ans);//bv[n]=new_ans;
		return *this;
	}

	size_t new_mark(const bitset<N>& mine) const {
		return (bv ^ mine).flip().count();
	}

private:
	bitset<N> bv;
};

int main(void)
{
	bitset<20> mine("1010010100101001010");
	Solution<20> quiz("1010010100101001010");
	quiz.update(0, true);
	cout << quiz.new_mark(mine) << endl;

	return 0;
}

//size_t mark(const bitset<N>& mine) const {
	//	cout << bv << endl;
	//	cout << mine << endl;
	//	size_t cnt = 0;
	//	for (size_t i = 0; i < N; ++i)
	//		if (mine[i] == bv[i])
	//			++cnt;
	//	return cnt;
	//}
