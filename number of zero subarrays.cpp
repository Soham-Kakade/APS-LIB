#include <iostram>
using namespace std;

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int flag = 0, count =0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            flag++;
        }
        else
            flag = 0;
        count += flag;
        // cout<<" "<<count;
    }
    return count;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)  cin>>arr[i];
    cout << number of subarrays is << no_of_subarrays(n, arr) << endl;
  }
  return 0;
}
