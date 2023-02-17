#include<math.h>
using namespace std;

int num_bits_set(int n)
{
    int cnt=0;
    for (int i = 0; i < sizeof(int)*8; i++)
        if (n&(1<<i))
            cnt++;
    return cnt;
}

int min_not_minus(int a,int b)
{
    if (a<0)
        return b;
    else if(b<0)
        return a;
    else if(a<b)
        return a;
    else
        return b;
}