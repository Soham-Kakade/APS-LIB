#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;


void multiply(unsigned long long F[2][2], unsigned long long M[2][2],unsigned long long m);
void power(unsigned long long F[2][2], unsigned long long n,unsigned long long m);

unsigned long long fib(unsigned long long n,unsigned long long m)
{
    unsigned long long F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1,m);

    return F[0][0];
}

// Optimized version of power() in method 4
void power(unsigned long long F[2][2], unsigned long long n,unsigned long long m)
{
    if(n == 0 || n == 1)
        return;
    unsigned long long M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2,m);
    multiply(F, F,m);

    if (n % 2 != 0)
        multiply(F, M,m);
}

void multiply(unsigned long long F[2][2], unsigned long long M[2][2],unsigned long long m)
{
    unsigned long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    unsigned long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    unsigned long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    unsigned long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x%m;
    F[0][1] = y%m;
    F[1][0] = z%m;
    F[1][1] = w%m;
}

int main()
{
    unsigned long long m=1000000007;
    unsigned long long n=0,su=0;
    cin>>n;
    unsigned long long s;
    int flag=0;
    cin>>s;
    su=s;
    for (int i=1; i<n; i++) {
        cin>>s;
        su=__gcd(su,s);
        if(su==1)
            flag=1;
    }
    if(flag==1)
        cout<<1<<"\n";
    else
    {
        su=fib(su,m);
        cout<<su<<"\n";
    }
return 0;
}
