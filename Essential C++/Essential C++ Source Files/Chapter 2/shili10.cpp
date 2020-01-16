#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void swap_value(int& value_1, int& value_2);
void show_vec(const vector<int>& vec,ostream &os=cout);//将其默认输出到cout之中
void bubble_sort(vector<int>& vec,ofstream *ofile=0);   /*将其默认不输出到文件之中，引用是不能被设置为
                                                        不代表任何对象（也就是说有引用就必须要让它代表一个对象）；
                                                        而指针却可以设置为空指针，不指向任何对象*/

int main(void)
{
	int arr[8] = { 2,3,6,4,3,1,87,32 };
	vector<int> vec(arr, arr + 8);
	show_vec(vec);
	ofstream ofile("data.txt");
	ofstream out_fileobj("show_out.txt");
	bubble_sort(vec,&ofile);
	show_vec(vec,out_fileobj);

	return 0;
}

void swap_value(int& value_1, int& value_2)
{
	int temp = value_1;
	value_1 = value_2;
	value_2 = temp;
}

void show_vec(const vector<int>& vec,ostream &os)
{
	for (int i = 0; i < vec.size(); i++)
		os << vec[i] << " ";
	os << endl;
}

void bubble_sort(vector<int>& vec,ofstream *ofile)//设置初始值
{
	int i, j;
	for (i = 0; i < vec.size(); i++)
		for (j = vec.size() - 1; j > 0; j--)
			if (vec[j - 1] > vec[j])
			{
			    if(ofile)
                    (*ofile)<<vec[j-1]<<" swap with "
                            <<vec[j]<<endl;
			    swap_value(vec[j - 1], vec[j]);
			}
}
