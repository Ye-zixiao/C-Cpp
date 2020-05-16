#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<utility>
#include"Sales_data.h"
using namespace::std;

/*
版本一：
*/
typedef tuple<
	vector<vector<Sales_data>>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;

bool compare(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}

vector<matches>
findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> ret;
	for (auto iter = files.cbegin(); iter != files.cend(); ++iter) {
		auto found = equal_range(iter->cbegin(), iter->cend(), Sales_data(book), compare);
		ret.push_back({ iter - files.cbegin(),found.first,found.second });
	}
	return ret;
}

/*
版本二：
*/

typedef vector<Sales_data>::const_iterator C_iter;
typedef pair<
	vector<vector<Sales_data>>::size_type,
	pair<C_iter, C_iter>> matches2;

vector<matches2>
findBook2(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches2> ret;
	for (auto iter = files.cbegin(); iter != files.cend(); ++iter) {
		auto found = equal_range(iter->cbegin(), iter->cend(), Sales_data(book), compare);
		ret.emplace_back(iter - files.cbegin(), found);
	}
	return ret;
}

/*
版本三：
*/

struct matches3 {
	using size_type = vector<vector<Sales_data>>::size_type;
	size_type pos;
	C_iter begin_citer;
	C_iter end_citer;
	matches3(size_type p, C_iter b, C_iter e) :
		pos(p), begin_citer(b), end_citer(e) {}
};

vector<matches3>
findBook3(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches3> ret;
	for (auto iter = files.cbegin(); iter != files.cend(); ++iter) {
		auto found = equal_range(iter->cbegin(), iter->cend(), Sales_data(book), compare);
		ret.emplace_back(iter - files.cbegin(), found.first, found.second);
	}
	return ret;
}

int main(void)
{
	vector<vector<Sales_data>> files{
		{Sales_data("System",12,22.2),Sales_data("helloworld",11,12.2),Sales_data("Computer",34,12.1)},
		{Sales_data("Operating System",12,11.1),Sales_data("Joker",45,34.1),Sales_data("Timer",32,12.1)},
		{Sales_data("Operating System",12,11.2),Sales_data("Computer",21,32.2)}
	};
	for (auto& elem : files)
		sort(elem.begin(), elem.end(),
			[](const Sales_data& lhs, const Sales_data& rhs) {return lhs.isbn() < rhs.isbn(); });

	auto result = findBook(files, "Operating System");
	for (const auto& store : result) {
		if (get<1>(store) != get<2>(store))
			cout << "store " << get<0>(store) << " sales: "
			<< accumulate(get<1>(store), get<2>(store), Sales_data("Operating System"))
			<< endl;
	}

	auto result2 = findBook2(files, "Operating System");
	for (const auto& store : result2) {
		if (store.second.first != store.second.second)
			cout << "store " << store.first << " sales: "
			<< accumulate(store.second.first, store.second.second, Sales_data("Operating System"))
			<< endl;
	}

	auto result3 = findBook3(files, "Operating System");
	for (const auto& store : result3) {
		if (store.begin_citer != store.end_citer)
			cout << "store " << store.pos << " sales: "
			<< accumulate(store.begin_citer, store.end_citer, Sales_data("Operating System"))
			<< endl;
	}

	return 0;
}