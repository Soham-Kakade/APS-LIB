#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INT_MAX 100000;

using namespace std;

int minSum(vector<int> v1, vector<int> v2, vector<int> v3) {
    int n = v1.size();
    int ans = INT_MAX;

    sort(v3.begin(), v3.end());

    for(int i=0; i<n; i++) {
        int j = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        int k = upper_bound(v3.begin(), v3.end(), v1[i]) - v3.begin();

        if(j > 0 && k < n) {
            ans = min(ans, abs(v2[j-1]-v1[i]) + abs(v2[j-1]-v3[k]) + abs(v3[k]-v1[i]));
        }
        if(j < n && k > 0) {
            ans = min(ans, abs(v2[j]-v1[i]) + abs(v2[j]-v3[k-1]) + abs(v3[k-1]-v1[i]));
        }
    }

    return ans;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    vector<int> v3 = {7, 8, 9};

    int result = minSum(v1, v2, v3);
    cout << "Minimum sum is: " << result << endl;

    return 0;
}
