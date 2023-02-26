#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {
			if (wt[i - 1] <= w)
				dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W];
}

int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 30;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout<<"The maximum profit that the Knapsack of weight "<<W<<" can get is "<<knapSack(W, weight, profit, n);
	return 0;
}
