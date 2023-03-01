#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, ans = 1;
    cout<<"Enter the number of elements in the array\n";
    cin>>n;
    vector<int> s;
    cout<<"Enter the numbers of the array\n";
    for(int i=0; i<n; i++)  {
        int x;
        cin>>x;
        s.push_back(x);
    }
    vector<int> LIS(n, 1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++) {
            if(s[i] > s[j] && LIS[j]+1 > LIS[i]) {
                LIS[i] = LIS[j]+1;
                ans = max(ans, LIS[i]);
            }
        }
    }
    //for(int i=0; i<n; i++)  cout<<LIS[i]<<" ";
    cout<<"The Longest Increasing Subsequence of the given array is "<<ans;
    return 0;
}
