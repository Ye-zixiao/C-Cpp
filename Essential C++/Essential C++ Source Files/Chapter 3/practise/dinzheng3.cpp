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
    while(getline(namefile,textline))                   //��ȡһ��
    {
        string fam_name;
        vector<string> child;
        string::size_type pos=0,prev_pos=0,             //size_type��string���ж����һ���޷�����������
            text_size=textline.size();                  //�����е���C�е�size_t
                                                        /*size_type����Ϊstring���е�ÿһ���ַ�
                                                        ��һ����ţ��硰abcd���е�d��size_typeλ�þ���3.
                                                        ������Ϊ�ַ�������*/
/*find_first_of�����ӵڶ��������������λ�ÿ�ʼ�ҵ�һ������ָ�����ַ������û���ҵ��͵���string�е�
һ��������npos��-1��*/

        while((pos=textline.find_first_of(' ',pos))!=string::npos)
        {
            string::size_type end_pos=pos-prev_pos;
            if(!prev_pos)
                fam_name=textline.substr(prev_pos,end_pos);         //����һ���ַ���
            else
                child.push_back(textline.substr(prev_pos,end_pos)); //��������ַ�������������뵽vector��
            prev_pos=++pos;                                         //����pre_pos
        }
                                                                /*substr��������һ��������������ַ�
                                                                λ�ÿ�ʼ�𣨵ڶ������������ַ��鲢Ϊһ��
                                                                �µ��ַ���*/
        if(prev_pos<text_size)
            child.push_back(textline.substr(prev_pos,pos-prev_pos));//��ȡ���һ���ַ���

        if(!families.count(fam_name))          //�����ǰmap������û�����pair����������pair��˵�ֵ�Ҳ���ԣ�
            families[fam_name]=child;          //��child�����鸶��map�������keyΪfam_name��value
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
