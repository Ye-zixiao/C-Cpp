#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    char ch;
    int vowel_cnt(0);
    cout<<"Please enter a character for this program: ";
    cin>>ch;
    cout<<vowel_cnt
        <<'\n';

    switch(ch)
    {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            vowel_cnt++;
            break;
    }
    cout<<"Now the number of vowel is "
        <<vowel_cnt
        <<".\n";

    return 0;
}
