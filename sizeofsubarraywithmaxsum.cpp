#include <iostream>
using namespace std;

int main() {
// your code goes here
int i,n;
int start,end;
int s;
int max_ending_here=0;
int max_so_far=0;
cin>>n;int a[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n;i++)
{
max_ending_here+=a[i];
if(max_ending_here >max_so_far)
{
max_so_far=max_ending_here;
start=s;
end=i;

}
else if(max_ending_here<0)
{
max_ending_here=0;
s=i+1;
}

}

cout<<start-end+1<<endl;
return 0;
}
