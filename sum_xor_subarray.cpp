#include <iostream>
using namespace std;

int sol(int a[], int n)
{
	int count =0;
	int l =0, r =0;
	int sum = 0;
	for(l=0; l<n; l++)
	{
		while((sum+a[r]) == (sum^a[r]) && r < n)
		{
			sum = sum + a[r];
			r++;
		}
		count = count + r - l;
		if(l == r)
			r++;
		else
			sum = sum - a[l];
	}
	return count;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		int ans = sol(a, n);
		cout<<"THE ANSWER IS : "<<ans<<endl;
	}
}
