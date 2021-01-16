#include<iostream>
#include<vector>
#include<string>
#include"Stack.h"

int main(void)
{
	Stack st;
	st.push("hello world");
	st.push("fuck you");
	st.push("niubiliaty");
	st.push("fuck you");
	st.push("fuck you");

	if (!st.empty())
		cout << "Not full!" << endl;

	string str = "fuck you";
	if (st.find(str))
		cout << "Find" << " and it occurs "
		<< st.count(str) << " times!" << endl;

	cout << "size=" << st.size() << endl;

	return 0;
}
