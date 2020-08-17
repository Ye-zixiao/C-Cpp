#include<iostream>
#include<bitset>
#include<cstdlib>
using namespace::std;

int main(void)
{
	char ch;
	while (ch = cin.get()) {
		bitset<32> bt(ch);//char到int会进行位拓展，也就是所若（有符号）char中的最高位（8）时转换成int时最高位的1会进行位拓展
							//此时11111111就会由最高位的1进行向更高位的1拓展，就全变成了111111111111111111111111111111111111，
							//此时就对应int中的-1
		cout << bt << endl;
		cout << ch << "line1" << endl;
		cout << static_cast<int>(ch) << "line2" << endl;
		if (ch == EOF)
			break;
	}
	cout << EOF << endl;

	/*for (unsigned n = 128; n != 256; ++n) {
		char ch = n;
		cout << ch << "line" << endl;
	}*/

	return 0;
}
