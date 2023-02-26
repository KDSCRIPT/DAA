#include<iostream>
using namespace std;
int main()
{
    string s,p;
    cout<<"Enter text:";
    cin>>s;
    cout<<"Enter pattern:";
    cin>>p;
    //creating lps array
    int lps[100];
    lps[0]=0;
    int i=1;
    int j=0;
    while (i<p.length())
    {
        if(p[i]==p[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        if(p[i]!=p[j] && j>0)
        {
            j=lps[j-1];
        }
        if(p[i]!=p[j] && j==0)
        {
            lps[i]=0;
            i++;
        }
    }
    i=0;
    j=0;
    while(i<s.length() && j<p.length())
    {
        if(s[i]==p[j])
        {
            j++;
            i++;
        }
        if(s[i]!=p[j] && j>0)
        {
            if(j==p.length())
            {
                cout<<"Found pattern at "<<i-p.length()<<endl;
            }
            j=lps[j-1];
        }
        if(s[i]!=p[j] && j==0)
        {
            i++;
        }
    }
}