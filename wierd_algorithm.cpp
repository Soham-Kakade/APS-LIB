#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    while(n>0)
    {
        if(n==1){
            cout<<n<<" ";
            return 0;}
        else if(n%2==0){
            cout<<n<<" ";
            n=n/2;}
        else{
            cout<<n<<" ";
            n=n*3+1;}
    }
    return 0;
}
