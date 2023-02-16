#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter number of elements in array \n";
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the sum you want to find \n";
    int sum;
    cin>>sum;
    int dp[n+1][sum+1] = {0};
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1; i<=sum; i++)
    {
        dp[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(dp[i-1][j] == 1)
                dp[i][j] = 1;
            else
            {
                if(a[i-1] > j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j-a[i-1]];
            }
        }
    }
    cout<<"The DP TABLE FORMED IS \n\n";
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<dp[n][sum]<<endl;
    if(dp[n][sum] == 1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}