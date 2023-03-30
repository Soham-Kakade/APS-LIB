#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, d;
	cin>>n>>d;
	vector<int> s;
	for(int i=0; i<n; i++)  {
	    int x;
	    cin>>x;
	    s.push_back(x);
	}
	sort(s.begin(), s.end());
	int count = 0;
	for(int i=0; i<n-1; i++) {
	    if(s[i+1] - s[i] <= d) {
	        count++;
	        i++;
	    }
	}
	cout<<count;
	return 0;
}

