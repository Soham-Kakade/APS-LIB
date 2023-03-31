#include <bits/stdc++.h>
using namespace std;

int maxWater(int height[], int n)
{
	int maximum = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int current
				= (min(height[i], height[j]) * (j - i - 1));

			maximum = max(maximum, current);
		}
	}
	return maximum;
}

int main()
{
	int height[] = { 2, 1, 3, 4, 6, 5 };
	int n = sizeof(height) / sizeof(height[0]);
	cout << maxWater(height, n);
	return 0;
}
