#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x, y, f = 0;
        cin>>x>>y;
        if(max(x, y) > 2*min(x,y)) {
            f = 1;
            cout<<"NO\n";
        }
        if(f == 0) {
            if((x+y) % 3 == 0) {
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
