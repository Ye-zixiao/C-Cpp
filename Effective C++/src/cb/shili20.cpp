#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

template<typename IterT>
struct Iter_traits {
	using value_type = typename IterT::value_type;
	using iterator_category = typename IterT::iterator_category;
	using difference_type = typename IterT::difference_type;
	using reference = typename IterT::reference;
	using pointer = typename IterT::pointer;
};

template<typename IterT>
struct Iter_traits<IterT*> {
	using value_type = IterT;
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = typename std::size_t;
	using reference = IterT&;
	using pointer = IterT*;
};

template<typename IterT,typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag) {
	iter += d;
}

template<typename IterT,typename DistT>
void doAdvance(IterT& iter, DistT d, std::bidirectional_iterator_tag) {
	if (d > 0)while (--d)++iter;
	else while (++d)--iter;
}

template<typename IterT,typename DistT>
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag) {
	if (d < 0)throw std::runtime_error("input_iterator can't add a negative distance\n");
	else
		while (--d)++iter;
}


template<typename IterT,typename DistT>
void Advance(IterT& iter, DistT d) {
	doAdvance(iter, d,typename Iter_traits<IterT>::iterator_category());
}

int main(void)
{
	vector<int> ivec(10); {
		int i = 0;
		for (auto& elem : ivec)
			elem = i++;
	}
	decltype(ivec)::iterator iter = ivec.begin();
	Advance(iter, 5);
	cout << *iter << endl;

	int arr[100]; {
		int i = 0;
		for (size_t i = 0; i < 100; ++i)
			arr[i] = i;
	}
	auto arr_iter = arr;
	Advance(arr_iter, 5);
	cout << *arr_iter << endl;

	return 0;
}
