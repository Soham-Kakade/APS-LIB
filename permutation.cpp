#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(n==1)
        cout<<1<<endl;
    else if(n==2||n==3)
        cout<<"NO SOLUTION"<<endl;
    else{
        for(long long int i=0;i<n;i++)
        {
            if(i<n/2)
                cout<<(2*(i+1))<<" ";
            else
                cout<<(2*(i-n/2)+1)<<" ";
        }
    }
    return 0;
}
