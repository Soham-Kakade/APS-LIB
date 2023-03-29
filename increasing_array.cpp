#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];

    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long int cnt=0;
    for(long long int i=1;i<n;i++)
    {
        if(a[i]<a[i-1]){
            cnt+=abs(a[i]-a[i-1]);
            a[i]=a[i-1];
            }
    }
    cout<<cnt;
}

