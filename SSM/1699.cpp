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

	int i, j, k, n, min = 0, dp[100001] = { 0 };
	cin >> n;

	for (i = 1; i < 4; i++) {
		dp[i] = i;
	}
	for (i = 4; i <= n; i++) {
		min = INT_MAX;
		for (j = 1; j * j <= i; j++) {
			min = minimum(min, dp[i - j * j] + 1);
		}
		dp[i] = min;
	}

	cout << dp[n];

	return 0;
}