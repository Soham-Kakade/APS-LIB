#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i<=n; i++)
    {
        for(int l=0; l<n-i; l++)
        {
            cout<<" ";
        }
        for(int j=i;j>0;j--)
        {
            cout<<j;
        }
        for(int k=0;k<=i;k++)
        {
            cout<<k;
        }
        cout<<endl;
    }

    return(0);
}
