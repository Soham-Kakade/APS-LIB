#include<iostream>
using namespace std;
#include<cmath>
#include<math.h>

int num_bits_set(int n)
{
    int cnt=0;
    for (int i = 0; i < sizeof(int)*8; i++)
        if (n&(1<<i))
            cnt++;
    return cnt;
}

int min_not_minus(int a,int b)
{
    if (a<0)
        return b;
    else if(b<0)
        return a;
    else if(a<b)
        return a;
    else
        return b;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n][n];
    int p=round(pow(2,n));
    cout<<"Enter the resource vs jobs matrix:";
    for (int i = 0; i < n; i++){
        for (int j= 0; j < n; j++) cin>>a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    // double p2 =  (int)(pow(2,n));
    // int p= (int)round(p2);
    int dp[p];
    // cout<<p<<endl;
    // cout<<"\ta[i][k]:"<<a[0][0];

    for (int i = 0; i < p; i++)
        dp[i]=-1;
    dp[0]=0;
    // cout<<dp[p-1];
    // for (int i = 0; i < p; i++)
    //     cout<<dp[i]<<" ";
    cout<<endl;
    for (int i = 0; i < p; i++)
    {
        int x=num_bits_set(i);
        // cout<<x<<endl;
        for (int k = 0; k < n; k++)
        {
            // cout<<"\ta[i][k]:"<<a[0][0];
            if(!(i&(1<<k)))
            {
                cout<<"i="<<i<<"\tbit:"<<k;
                cout<<"\tdp[i|(1<<x)]:"<<dp[i|(1<<k)]<<"\ta[x][k]:"<<a[x][k];
                int t=0;
                if (dp[i|(1<<k)]==-1)
                    dp[i|(1<<k)]=dp[i]+a[x][k];
                else
                {
                    if (dp[i]==-1)
                        dp[i|(1<<k)]=min_not_minus(dp[i|(1<<k)],(t+a[x][k]));
                    else
                    {
                        // cout<<"HELLO";
                        dp[i|(1<<k)]=min_not_minus(dp[i|(1<<k)],(dp[i]+a[x][k]));
                    }
                }
                cout<<"\tdp[i|(1<<x)]:"<<dp[i|(1<<k)]<<endl;
            }
        }
        // cout<<"Hello";
    }
    cout<<"DP table for the minimun resource allocation:"<<endl;
    for (int i = 0; i < p; i++)
    {
        cout<<dp[i]<<" ";
    }
    return 0;
}
