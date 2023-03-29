#include<iostream>
#include<algorithm>
#include<math.h>

#define ll long long
using namespace std;

int main()
{
    int t;
    ll y,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x<y){
            if(y%2!=0)
                ans=(y*y)-x+1;
            else
                ans=((y-1)*(y-1))+x;
                cout<<ans<<endl;
        }
        else{
            if(x%2!=0)
                ans=((x-1)*(x-1))+y;
            else
                ans=(x*x)-y+1;
                cout<<ans<<endl;
        }
    }
}
