#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

/*������һ�����������ڵ��ú���ʱʹ�ú�������͵�Ч��ʹ�ú���ָ�롣
    ��������������ݣ�����ż������true*/
class even_elem{
public:
    bool operator()(int elem)
    {
        return elem%2?false:true;
    }
};

int main(void)
{
    ofstream even_file("even_file.txt");
    ofstream odd_file("odd_file.txt");
    if(!even_file||!odd_file)
    {
        cerr<<"Error in opening file"<<endl;
        return -1;
    }

    istream_iterator<int> in(cin);                  //�����������������ף����׼�����豸��
    istream_iterator<int> eof;
    vector<int> temp_vec;

    copy(in,eof,back_inserter(temp_vec));           //�����������������׵�β�����ݿ�������ʱ����vector��
    vector<int>::iterator division=stable_partition(temp_vec.begin(),
        temp_vec.end(),even_elem());                /*partition�㷨�����þͽ�����even_elem��������Ĺ���
                                                    ����ֵΪtrue��Ԫ�طŵ���ֵΪfalseԪ�ص�ǰ�档stable_partition
                                                    ��ʾ�㷨ִ�к󲻻�ı�ԭ�����˳��*/

    ostream_iterator<int> even_put(even_file, z"\n");
    ostream_iterator<int> odd_put(odd_file," ");    //�������������ָ���ض�����������е���C�е��ض���

    copy(temp_vec.begin(),division,even_put);       /*����ż����ǰ|�����ں����Խ�divisionǰ��ĸ��Ƶ�ż���ļ��У�
                                                    ��������������ļ���*/
    copy(division,temp_vec.end(),odd_put);

    return 0;
}
