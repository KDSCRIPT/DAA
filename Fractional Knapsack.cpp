#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n,pricelist[100],weightlist[100];
    float ratiolist[100];
    cout<<"Enter number of items:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int price,weight;
        cout<<"Enter item price:";
        cin>>price;
        cout<<"Enter item weight:";
        cin>>weight;
        pricelist[i]=price;
        weightlist[i]=weight;
        ratiolist[i]=(float)price/weight;
    }
    int w;
    cout<<"Enter capacity of knapsack:";
    cin>>w;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ratiolist[j]<ratiolist[j+1])
            {
                int t=ratiolist[j];
                ratiolist[j]=ratiolist[j+1];
                ratiolist[j+1]=t;
                int u=pricelist[j];
                pricelist[j]=pricelist[j+1];
                pricelist[j+1]=u;
                int v=weightlist[j];
                weightlist[j]=weightlist[j+1];
                weightlist[j+1]=v;
            }
        }
    }
    float worth=0;
    for(int i=0;i<n;i++)
    {
        if(w-weightlist[i]>=0)
        {
            w=w-weightlist[i];
            worth+=pricelist[i];
        }
        else
        {
            worth+=((float)w/weightlist[i])*pricelist[i];
            w=w-((float)w/weightlist[i])*weightlist[i];
            break;
        }
    }
    cout<<"Maximum profit that can be obtained:"<<worth;
}