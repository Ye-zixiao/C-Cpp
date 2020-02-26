#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;

int main(void)
{
	string final_str, temp_str;
	if (cin >> final_str)
	{
		while (cin >> temp_str)
		{
			/*string temp = ' ' + temp_str;
			final_str += temp;*/
			//final_str += string(' ' + temp_str);
			final_str += ' ' + temp_str;//这几种方式都具有等价性
		}

		cout << "The final string is: "
			<<"\n\t" << final_str << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "No data?" << std::endl;
		return -1;
	}
}
