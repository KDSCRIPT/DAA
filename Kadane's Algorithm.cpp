#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    cout<<"Enter elements of array:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" value:";
        cin>>a[i];
    }
    int max_sum=INT_MIN;
    int cur_sum=0;
    int start_index=0;
    int end_index=0;
    int cur_index=0;
    for(int i=0;i<n;i++)
    {
        cur_sum=cur_sum+a[i];
        if(max_sum<cur_sum)
        {
            max_sum=cur_sum;
            start_index=cur_index;
            end_index=i;
        }
        if(cur_sum<0)
        {
            cur_sum=0;
            cur_index=i+1;
        }
    }
    cout<<"Maximum subaraay sum:"<<max_sum<<endl;
    cout<<"Starting index:"<<start_index<<endl;
    cout<<"Ending index:"<<end_index<<endl;
}