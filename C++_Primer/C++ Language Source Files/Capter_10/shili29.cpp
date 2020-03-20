#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace::std;

void func(const string&infilename,const string&outevenfile,const string&outoddfile)
{
    ifstream in_file(infilename,ifstream::in);
    ofstream even_file(outevenfile,ofstream::out),odd_file(outoddfile,ofstream::out);
    if(!in_file&&!even_file&&!odd_file)
    {
        cerr<<"can't open this file"<<endl;
        return;
    }

    istream_iterator<int> in_iter(in_file),eof;
    ostream_iterator<int> odd(odd_file,"\n"),even(even_file,"\n");
    for_each(in_iter,eof,[odd,even](int value)mutable{*(value&0x1?odd:even)++=value;});//流对象是不能拷贝赋值的，而流迭代器是可以拷贝赋值的
    //for_each(in_iter,eof,[&odd,&even](int value){(value%2)?(odd=value):(even=value);});正确
    //for_each(in_iter,eof,[odd,even](int value){(value%2)?(odd=value):(even=value);});错误
    //因为odd和even会被捕获列表值捕获，并会在lambda未命名类中生成默认const数据成员，显然我们不能
    //向一个const ostream_iterator写入数据，唯一的方法就是在参数列表后面加上mutable关键字

    //在使用流迭代器的时候，保持以一种解引用表示获取流迭代器指向的流对象，++表示输出下一个流这种习惯会更好
    //（虽然在实际中语法上允许out=的方式，但是希望多使用*out++=value的方式）
}

int main(void)
{
	func("in_file.txt", "out_even.txt", "out_odd.txt");
	return 0;
}
