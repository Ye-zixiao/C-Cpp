#include<iostream>
#include<bitset>
#include<cstdlib>
using namespace::std;

int main(void)
{
	char ch;
	while (ch = cin.get()) {
		bitset<32> bt(ch);//char��int�����λ��չ��Ҳ�����������з��ţ�char�е����λ��8��ʱת����intʱ���λ��1�����λ��չ
							//��ʱ11111111�ͻ������λ��1���������λ��1��չ����ȫ�����111111111111111111111111111111111111��
							//��ʱ�Ͷ�Ӧint�е�-1
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
