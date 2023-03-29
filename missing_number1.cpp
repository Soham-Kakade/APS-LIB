#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long n,s=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a;
        cin>>a;
        s+=a;
    }
    cout<< n*(n+1)/2-s;

}
