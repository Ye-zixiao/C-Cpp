#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> &vec);
void show_vec(vector<int> &vec);
void swap_value(int *value1,int *value2);

int main(void)
{
    int arr[4]={2,5,3,1};
    vector<int> vec(arr,arr+4);
    bubble_sort(vec);
    show_vec(vec);

    return 0;
}

void bubble_sort(vector<int> &vec)
{
    int i;
    int j;
    for(i=0;i<vec.size();i++)
        for(j=vec.size()-1;j>0;j--)
            if(vec[j-1]>vec[j])
            {
                cout<<vec[j-1]<<" swap with "<<vec[j]<<endl;
                swap_value(&vec[j-1],&vec[j]);
            }
}

void show_vec(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void swap_value(int *value1,int *value2)
{
    int temp;
    temp=*value1;
    *value1=*value2;
    *value2=temp;
}
