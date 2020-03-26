#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace::std;

size_t len(const char* pcarr)
{
	size_t len = 0;
	while (*pcarr++)
		++len;
	return len;
}

int main(void)
{
	const char* pc1 = "hello world", * pc2 = " show me the world";
	size_t length = len(pc1) + len(pc2);
	char* pcarr = new char[length];
	for (size_t i = 0; i < length; ++i){
		if (i < len(pc1))
			pcarr[i] = pc1[i];
		else
			pcarr[i] = pc2[i-len(pc1)];
		cout << pcarr[i];
	}
	cout << endl;
	delete[]pcarr;

	return 0;
}
