#include<iostream>
#include<string>
#include<cstring>
using namespace::std;

template<unsigned larr_sz,unsigned rarr_sz>
inline
int compare(const char(&lhs)[larr_sz], const char(&rhs)[rarr_sz]) {
	return strcmp(lhs, rhs);
}

int main(void)
{
	cout << compare("zoo show", "worlder") << endl;

	return 0;
}
