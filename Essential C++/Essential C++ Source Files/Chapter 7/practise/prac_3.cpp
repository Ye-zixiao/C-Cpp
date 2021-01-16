#include<fstream>
#include<iostream>
#include<string>
#include<exception>
using namespace std;

int *alloc_and_init(string file_name)           //分配空间并初始化函数
{
    ifstream infile(file_name.c_str());
    if(!infile)                                 //检查文件能否打开
        return 0;

    int elem_cnt;
    infile>>elem_cnt;
    if(!infile)                                 /*检查ifstream类对象infile是否能够阅读，因为file_name文件中
                                                第一个数据不一定是int型的数据，所以此时不一定能够输入*/
        return 0;

    try
    {
        int *pi=allocate_array(elem_cnt);           //异常1：可能不会为这个函数分配相应的内存空间
        int elem;
        int index=0;
        while(infile>>elem&&index<elem_cnt)         //需要注意：不要让索引超过数据长度
            pi[index++]=elem;

        sort_array(pi,elem_cnt);
        register_data(pi);
    }
    catch(const noMem& memFail)                     //处理未为函数分配空间的异常
    {
        cerr<<"alloc_and_init():allocate_array failure!\n"
            <<memFail.what()<<endl;
        return 0;
    }
    catch(int& sortFail)                            //处理排序中抛出的异常
    {
        cerr<<"alloc_and_init():sort_array failure!\n"
            <<"thrown int value: "<<sortFail<<endl;
        return 0;
    }
    catch(string & registerFail)                    //处理寄存器数据中抛出的异常
    {
        cerr<<"alloc_and_init():register_data failure!\n"
            <<"thrown string value: "<<registerFail<<endl;
        return 0;
    }

    return pi;
}
