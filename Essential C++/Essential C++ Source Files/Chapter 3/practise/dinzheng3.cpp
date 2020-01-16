#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

typedef vector<string> vstring;

void populate_map(ifstream &namefile,map<string,vstring> &families);
void display_map(const map<string,vstring> &families,ostream &os);
void query_map(const string &family,const map<string,vstring> &families);

int main(void)
{
    map<string,vstring> families;
    ifstream nameFile("families.txt");
    if(!nameFile)
    {
        cerr<<"Unable to find families.txt file.\n";
        return -1;
    }

    populate_map(nameFile,families);

    string family_name;
    while(1)
    {
        cout<<"Please enter a family name or q to quit ";
        cin>>family_name;

        if(family_name=="q")
            break;
        query_map(family_name,families);
    }
    display_map(families,cout);

    return 0;
}

void populate_map(ifstream &namefile,map<string,vstring> &families)
{
    string textline;
    while(getline(namefile,textline))                   //读取一行
    {
        string fam_name;
        vector<string> child;
        string::size_type pos=0,prev_pos=0,             //size_type是string类中定义的一个无符号整型类型
            text_size=textline.size();                  //作用有点像C中的size_t
                                                        /*size_type类型为string类中的每一个字符
                                                        计一个序号，如“abcd”中的d的size_type位置就是3.
                                                        而不是为字符串计数*/
/*find_first_of函数从第二个参数所代表的位置开始找第一个参数指定的字符，如果没有找到就等于string中的
一个特殊数npos（-1）*/

        while((pos=textline.find_first_of(' ',pos))!=string::npos)
        {
            string::size_type end_pos=pos-prev_pos;
            if(!prev_pos)
                fam_name=textline.substr(prev_pos,end_pos);         //读第一个字符串
            else
                child.push_back(textline.substr(prev_pos,end_pos)); //读后面的字符串，并将其计入到vector中
            prev_pos=++pos;                                         //更新pre_pos
        }
                                                                /*substr函数将第一个参数所代表的字符
                                                                位置开始起（第二个参数）个字符归并为一个
                                                                新的字符串*/
        if(prev_pos<text_size)
            child.push_back(textline.substr(prev_pos,pos-prev_pos));//读取最后一个字符串

        if(!families.count(fam_name))          //如果当前map对象中没有这个pair，就添加这个pair（说字典也可以）
            families[fam_name]=child;          //将child向量组付给map类对象中key为fam_name的value
        else
            cerr<<"Oops!We already have a "
                <<fam_name<<" family in our map!"<<endl;
    }
}

void display_map(const map<string,vstring> &families,ostream &os)
{
    map<string,vstring>::const_iterator it=families.begin(),
        end_it=families.end();

    while(it!=end_it)
    {
        os<<"The "<<it->first<<" family ";
        if(it->second.empty())
            os<<"has no children\n";
        else
        {
            os<<"has "<<it->second.size()<<" children: ";
            vector<string>::const_iterator iter=it->second.begin(),
                end_iter=it->second.end();
            while(iter!=end_iter)
            {
                os<<*iter<<" ";
                iter++;
            }
            os<<endl;
        }
        it++;
    }
}

void query_map(const string &family,const map<string,vstring> &families)
{
    map<string,vstring>::const_iterator it=families.find(family);

    if(it==families.end())
    {
        cout<<"Sorry,The "<<family
            <<" is not currently entered.\n";
        return;
    }

    cout<<"The "<<family;
    if(!it->second.size())
        cout<<" has no children\n";
    else
    {
        cout<<" has "<<it->second.size()<<" children: ";
        vector<string>::const_iterator iter=it->second.begin(),
            end_iter=it->second.end();
        while(iter!=end_iter)
        {
            cout<<*iter<<" ";
            iter++;
        }
        cout<<endl;
    }
}
