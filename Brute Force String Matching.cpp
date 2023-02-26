#include<iostream>
using namespace std;
int main()
{
    string s,p;
    cout<<"Enter text:";
    cin>>s;
    cout<<"Enter pattern to be found:";
    cin>>p;
    int m=s.length();
    int n=p.length();
    for(int i=0;i<m-n+1;i++)
    {
        if(s.substr(i,n)==p)
        {
            cout<<"Pattern found at index "<<i<<endl;
        }
    }
}