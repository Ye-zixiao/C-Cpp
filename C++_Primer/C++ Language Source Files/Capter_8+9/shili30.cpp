#include<iostream>
#include<string>
#include<fstream>
#define NDEBUG
using namespace::std;

string find_nad(const string&filename, const string& ad)
{
	ifstream infile(filename, ifstream::in);
	string temp, temp_max;
	if (infile)
	{
		while (infile >> temp){
			if (temp.find_first_of(ad) == string::npos)
				temp_max = temp.size() > temp_max.size() ? temp : temp_max;
            #ifndef NDEBUG
            cout << "input: " << temp << " output: " << temp_max << endl;//用于调试之用
            #endif // NDEBUG
		}
		infile.close();
	}
	else
		cerr << "Can't open this file" << endl;

	return temp_max;
}

int main(void)
{
	const string ad("bdfhkpgyq");
	cout << find_nad("infile.txt", ad) << endl;

	return 0;
}
