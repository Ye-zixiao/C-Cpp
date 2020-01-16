#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int next_elem = 9;
	bool next_seq = true; //�Ƿ�����ʾ����
	bool go_for_it = true;//�Ƿ������
	bool got_it = false;  //�Ƿ�¶�
	int num_tries = 0;
	int num_right = 0;
	const int arr[] = { 0,3,6,9,12,15 };
	int pst_num(0);
	const int max_tries_time = 3;
	int tries_time = 1;

	while (next_seq == true&&tries_time<=max_tries_time)
	{
	    /*==============��ӡ���������ֵ�ǰ��������===============*/
		tries_time++;
		int i;
		cout << "Look at the next seq:\n";
		for (i = 0; i < 2; i++)
		{
			cout << arr[pst_num + i];
			cout << " ";
		}

        /*======================�²ⲿ��======================*/
		cout << "\nPlease guess the next seqnumber.\n";
		while (go_for_it && !got_it)
		{
			int user_guess;
			cout << "Please enter your answer: ";
			cin >> user_guess;
			num_tries++;
			if (user_guess == arr[pst_num + 2])
			{
				got_it = true;
				num_right++;
			}
			else
			{
				cout << "Sorry,you are wrong.\n";
				cout << "Do you want to guess again?(y/n)\n";
				char user_rsp;
				cin >> user_rsp;
				if (user_rsp == 'n' || user_rsp == 'N')
					go_for_it = false;
			}
		}

        /*==================�Ƿ����ٲ�һ��=================*/
		if(tries_time<max_tries_time)
			cout << "Do you want try another sequence?(y/n)\n";
			char try_again;
			cin >> try_again;
			if (try_again == 'n' || try_again == 'N')
				next_seq = false;
			pst_num++;
	}
	cout << "It's over!\n";

	return 0;
}
