#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of coins\n";
    cin>>n;
    cout<<"Enter your coins\n";
    int c[n];
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    sort(c, c+n);
    int k;
    cout<<"Enter the sum you want to achieve\n";
    cin>>k;
    int dp[k+1] = {0};
    dp[0] = 1;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            if(i - c[j] == 0) {
                dp[i] = 1;
                break;
            }
            else if(i - c[j] >= 0) {
                if(dp[i-c[j]] >= 0) {
                    int y = dp[i-c[j]] + 1;
                    if(y < dp[i] || dp[i] == 0)
                        dp[i] = y;
                }
            }
        }
    }
    for(int i=0; i<=k; i++) cout<<dp[i]<<" ";
    cout<<"\nThe Minimum number of coins required to get sum "<<k<<" is "<<dp[k];
    return 0;
}
