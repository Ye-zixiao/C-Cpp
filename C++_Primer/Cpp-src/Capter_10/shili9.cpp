#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

template<typename Seq>
ostream& print(const Seq& sequence, ostream& os = cout)
{
	for (const auto elem : sequence)cout << elem << ' '; return os;
}

template<typename Seq>
void elimDups(Seq& sequence)
{
	print(sequence) << endl;
	sort(sequence.begin(), sequence.end());
	print(sequence) << endl;
	auto unique_end_iter = unique(sequence.begin(), sequence.end());
	print(sequence) << endl;
	sequence.erase(unique_end_iter, sequence.end());
	print(sequence) << endl;
	return;
}

int main(void)
{
	vector<int> ivec;
	for (decltype(ivec)::size_type i = 5; i > 0; --i)
	{
		ivec.push_back(i); ivec.push_back(i);
	}

	elimDups(ivec);

	return 0;
}
