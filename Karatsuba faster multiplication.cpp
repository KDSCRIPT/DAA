#include<iostream>
#include<string>
using namespace std;
long long int karatsuba(long long int x, long long int y) 
{
    if (x < 10 || y < 10) 
    {
        return x * y;
    } 
    else 
    {
        long long int n = max(to_string(x).length(), to_string(y).length());
        long long int half = n / 2;
        long long int a = x / (long long int)pow(10, half);
        long long int b = x % (long long int)pow(10, half);
        long long int c = y / (long long int)pow(10, half);
        long long int d = y % (long long int)pow(10, half);
        long long int ac = karatsuba(a, c);
        long long int bd = karatsuba(b, d);
        long long int ad_plus_bc = karatsuba(a+b, c+d) - ac - bd;
        return ac * (long long int)pow(10, 2 * half) + (ad_plus_bc * (long long int)pow(10, half)) + bd;
    }
}
int main()
{
    long long int x;
    cout<<"Enter first number:";
    cin>>x;
    long long int y;
    cout<<"Enter second number:";
    cin>>y;
    cout<<"product="<<karatsuba(x,y)<<endl;

}