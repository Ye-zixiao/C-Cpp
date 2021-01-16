#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
    int i=0;
    const int max_size=30;
    string word;
    vector<string> talk(max_size);

    ifstream infile("practice.txt");
    ofstream outfile("outfile.txt");
    if(!infile)
        cerr<<"Can't open this file"<<endl;
    else
    {
        while(true)
        {
            if(!(infile>>word))
                break;
            else
                talk[i]=word;
            i++;
        }
        for(int j=0;j<i;j++)
            cout<<talk[j]<<" ";
    }

    sort(talk.begin(),talk.end());
    cout<<endl;
    for(int j=0;j<i;j++)
        outfile<<talk[i]<<" ";

    return 0;
}
