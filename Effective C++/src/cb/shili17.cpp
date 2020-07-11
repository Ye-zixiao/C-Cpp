#include<iostream>
#include<iterator>
#include<string>
#include<list>
using namespace std;


template<typename Iter>
auto func(Iter iter)->
typename iterator_traits<Iter>::value_type {
	return *iter;
}

int main(void)
{
	list<int> il{ 1,2,3,4 };
	for (auto iter = il.begin(); iter != il.end(); ++iter)
		cout << func(iter) << ' '; cout << endl;

	return 0;
}
