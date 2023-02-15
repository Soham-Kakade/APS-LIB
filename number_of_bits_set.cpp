#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    cin>>n;
    for(int i = 0; i<sizeof(int) * 8; i++ )
    {
        if(n & (1<<i))
            cnt++;
    }
    cout<<"Number of bits set are "<<cnt<<endl;
    return 0;
}
