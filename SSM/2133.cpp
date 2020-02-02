#include <iostream>
#include <limits.h>
using namespace std;

int minimum(int a, int b) {
	int min = a;
	if (min > b) min = b;
	return min;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k, n, min = 0, dp[31] = { 0 };
	cin >> n;

	dp[2] = 3;
	if (n % 2 == 1) {
		cout << 0;
	}
	else {
		for (i = 4; i <= n; i += 2) {
			for (j = 2; j < i; j += 2) {
				dp[i] += dp[j] * 2;
			}
			dp[i] += dp[i - 2] + 2;
		}
		cout << dp[n];
	}

	return 0;
}