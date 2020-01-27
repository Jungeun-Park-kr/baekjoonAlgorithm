#include <iostream>
#include <string>

using namespace std;

int maximum(int a, int b) {
	int max = a;
	if (max < b) max = b;
	return max;
}
int maximum(int a, int b, int c) {
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

int main() {
	int i, j, input, n, dp[1001] = { 0 }, w[1001] = { 0 }, max;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> w[i];
	}

	//√ ±‚
	dp[1] = w[1];
	max = dp[1];
	//DP
	for (i = 2; i <= n; i++) {
		j = i;
		dp[i] = w[i];
		while (--j) {
			if (w[j] < w[i])
				dp[i] = maximum(dp[i], dp[j] + w[i]);
		}
		max = maximum(max, dp[i]);
		//cout << dp[i] << '\n';
	}
	cout << max;

	return 0;
}