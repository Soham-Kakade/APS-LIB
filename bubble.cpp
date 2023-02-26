#include<iostream>
using namespace std;

sorta(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<a[i]<<endl;
    }
}

int main()
{
    int a[10]= {2,3,4,7,1,2,8,3,7,11};
    display(a,10);
    sorta(a,10);
    cout<<endl;
    display(a,10);

    return(0);
}
