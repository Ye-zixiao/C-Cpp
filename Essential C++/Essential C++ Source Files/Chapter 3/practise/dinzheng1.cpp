#include<iostream>
#include<set>
#include<map>
#include<string>
#include<fstream>
using namespace std;

void init_exclusion_set(set<string> &ex_set);
void process_file(map<string,int> &word_ct,const set<string> &ex_set,
                    ifstream &infile);
void user_query(const map<string,int> &word_ct);
void display_word_count(const map<string,int> &word_ct,ofstream &os);

int main(void)
{
    ifstream infile("column.txt");
    ofstream outfile("column_out.txt");
    if(!infile||!outfile)
    {
        cerr<<"Error!"<<endl;
        return -1;
    }

    set<string> ex_set;
    init_exclusion_set(ex_set);             //��ʼ���ų���set

    map<string,int> word_ct;
    process_file(word_ct,ex_set,infile);    //�����ļ��е����ݣ�������д���Ȼ��ŵ�map��
    user_query(word_ct);                    //�û�������Ѱ
    display_word_count(word_ct,outfile);    //��map�е�����д�뵽�ļ���

    return 0;
}

void init_exclusion_set(set<string> &ex_set)
{
    static string ex_clu[25]={
        "then","and","but","that","the",
        "are","been","can","for","is",
        "could","have","had","his","its",
        "were","which","when","with","would",
        "a","an","for","did","him"
    };

    ex_set.insert(ex_clu,ex_clu+25);
}

void process_file(map<string,int> &word_ct,const set<string> &ex_set,
                    ifstream &infile)
{
    string word;
    while(infile>>word)
    {
        if(ex_set.count(word))
            continue;
        else
            word_ct[word]++;
    }
}

void user_query(const map<string,int> &word_ct)
{
    string search_word;
    cout<<"Please enter a word to search:(q to quit) ";
    cin>>search_word;
    while(search_word.size()&&search_word!="q")
    {
        map<string,int>::const_iterator iter;
        if((iter=word_ct.find(search_word))!=word_ct.end())
            cout<<"Found!"<<iter->first
                <<" occurs "<<iter->second
                <<" times"<<endl;
        else
            cout<<search_word<<"was not found in text!"<<endl;
        cout<<"Another search?(q to quit) ";
        cin>>search_word;
    }
}

void display_word_count(const map<string,int> &word_ct,ofstream &os)
{
    map<string,int>::const_iterator iter=word_ct.begin(),
        end_it=word_ct.end();
    while(iter!=end_it)
    {
        os<<iter->first<<"("
            <<iter->second<<")"<<endl;
        iter++;
    }
    os<<endl;
}
