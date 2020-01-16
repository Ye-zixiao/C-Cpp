#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int arr[9]={
        1,2,3,1,4,9,2,4,6
    };

const char *msg_to_user(int index);

int main(void)
{
    vector<int> value_seq(arr,arr+9);
    cout<<"Let's do some game"<<endl;
    int i,seq_index=0;
    int num_tries=0;
    int num_right=0;
    int wrong_time=0;

    while(seq_index<9)
    {
        int answer;
        num_tries++;
        cout<<"From the sequence below,guess which number is the next?"<<endl;
        for(i=0;i<2;i++)
            cout<<value_seq[seq_index+i]<<" ";
        cout<<"\nEnter your answer: ";
        cin>>answer;

        if(answer==value_seq[seq_index+i])                                  //猜对了
        {
            cout<<"Congratulation!You are right!"<<endl;
            num_right++;
        }
        else                                                                //猜错了
        {
            wrong_time++;
            cout<<msg_to_user(wrong_time)<<endl;
            cout<<"Would you like to keep this question again?(y/n) ";
            char user_rsp;
            cin>>user_rsp;
            if(user_rsp=='n'||user_rsp=='N')
            {
                seq_index+=3;
                wrong_time=0;
                cout<<endl;
            }
            else
                continue;
        }

        if(seq_index<6)                                                 //前两次
        {
            cout<<"Would you like to do next question again?(y/n) ";
            char user_rsp;
            cin>>user_rsp;
            if(user_rsp=='n'||user_rsp=='N')
                break;
            else
            {
                seq_index+=3;
                wrong_time=0;
                cout<<endl;
            }
        }
        else                                                            //最后一次
            seq_index+=3;
    }

    return 0;
}

const char *msg_to_user(int index)
{
    const int msg_cnt=5;
    static const char *msg[msg_cnt]={
        "Go on,make a guess.",
        "Oops!Nice guess but not quite it.",
        "Hmm.Sorry.Wrong a second time.",
        "Ah,this is harder than it looks,no?",
        "It must be getting pretty frustrating by now!",
    };

    if(index<0)
        index=0;
    else if(index>msg_cnt-1)
        index=msg_cnt-1;

    return msg[index];
}
