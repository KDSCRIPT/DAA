#include<iostream>
using namespace std;
int main()
{
    string s,p;
    cout<<"Enter Text:";
    cin>>s;
    cout<<"Enter Pattern:";
    cin>>p;
    int hash_s=0,hash_p=0,d=26,q=101;
    int m=s.length(),n=p.length();
    int h=(int)pow(d,n-1)%q;
    for(int i=0;i<n;i++)
    {
        hash_p=(hash_p*d+int(p[i]))%q;
        hash_s=(hash_s*d+int(s[i]))%q;
    }
    for(int i=0;i<m-n+1;i++)
    {
        if(hash_s==hash_p)
        {
            if(s.substr(i,n)==p)
            {
                cout<<"Pattern found at index "<<i<<endl;
            }
        }
        if(i<m-n)
        {
            hash_s=(d*(hash_s-int(s[i])*h)+int(s[i+n])) % q;
            hash_s=(hash_s+q)%q;
        }
    }
}
