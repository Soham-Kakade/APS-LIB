#include <bits/stdc++.h>
using namespace std;

bool curPreferred(vector<vector<int>> &prefer, int w,int b, int m)
{
    for(int i=0;i<prefer[0].size();i++)
    {
        if(prefer[w][i] == b)
          return false;

         if(prefer[w][i] == m)
          return true;
    }
}
void solve()
{
    int n,x;
    cin>>n;

    vector<vector<int>> prefer((2*n),vector<int>(n));

    for(int i=0;i<(2*n);i++)
    {
        cin>>x;
        for(int j=0;j<n;j++)
        {
             cin>>x;
             prefer[i][j] = x;
        }
    }

    vector<int> women(n+1,-1), mfree(n+1,true);

    int remainMen = n;

    while(remainMen > 0)
    {
        int m;
        for( m=1;m<=n;m++)
         {
             if(mfree[m] == true)
               break;
         }
         for(int i=0;i<n && (mfree[m] == true);i++)
         {
             int w = prefer[m+n-1][i];

             if(women[w] == -1)
             {
                 women[w] = m;
                 remainMen--;
                 mfree[m] = false;
             }
             else
             {
                 int mb = women[w];
                 if(curPreferred(prefer,w-1,mb,m))
                 {
                     women[w] = m;
                     mfree[m] = false;
                     mfree[mb] = true;
                 }
             }
         }
    }
      vector<int> men(n+1,0);
     for(int i=1;i<=n;i++)
         {

             men[women[i]] = i;
         }

         for(int i=1;i<=n;i++)
         {
             cout<<i<<" "<<men[i]<<endl;
         }
}

int main() {
	int t;
	cin>>t;

	while(t--)
	{
	    solve();
	}
	return 0;
}
