#include<iostream>
using namespace std;

void insort(int *a, int n)
{
    int key, j;
    for(int i = 1; i<n; i++)
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]= key;
    }
}

void print(int *a, int n)
{
    for(int i =0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[8] = {2,5,3,7,1,7,3,8};
    print(a, 8);
    insort(a,8);
    print(a, 8);
    return 0;
}
