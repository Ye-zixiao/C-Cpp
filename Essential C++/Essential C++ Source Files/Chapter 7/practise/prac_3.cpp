#include<fstream>
#include<iostream>
#include<string>
#include<exception>
using namespace std;

int *alloc_and_init(string file_name)           //����ռ䲢��ʼ������
{
    ifstream infile(file_name.c_str());
    if(!infile)                                 //����ļ��ܷ��
        return 0;

    int elem_cnt;
    infile>>elem_cnt;
    if(!infile)                                 /*���ifstream�����infile�Ƿ��ܹ��Ķ�����Ϊfile_name�ļ���
                                                ��һ�����ݲ�һ����int�͵����ݣ����Դ�ʱ��һ���ܹ�����*/
        return 0;

    try
    {
        int *pi=allocate_array(elem_cnt);           //�쳣1�����ܲ���Ϊ�������������Ӧ���ڴ�ռ�
        int elem;
        int index=0;
        while(infile>>elem&&index<elem_cnt)         //��Ҫע�⣺��Ҫ�������������ݳ���
            pi[index++]=elem;

        sort_array(pi,elem_cnt);
        register_data(pi);
    }
    catch(const noMem& memFail)                     //����δΪ��������ռ���쳣
    {
        cerr<<"alloc_and_init():allocate_array failure!\n"
            <<memFail.what()<<endl;
        return 0;
    }
    catch(int& sortFail)                            //�����������׳����쳣
    {
        cerr<<"alloc_and_init():sort_array failure!\n"
            <<"thrown int value: "<<sortFail<<endl;
        return 0;
    }
    catch(string & registerFail)                    //����Ĵ����������׳����쳣
    {
        cerr<<"alloc_and_init():register_data failure!\n"
            <<"thrown string value: "<<registerFail<<endl;
        return 0;
    }

    return pi;
}
