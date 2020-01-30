#include <iostream>
#include <stdlib.h>

using namespace std;

int maximum(int a, int b) {
	int max = a;
	if (max < b) max = b;
	return max;
}

int main() {

	int num, i, dp[301] = { 0 }, w[301] = { 0 };

	cin >> num;

	for (i = 1; i <= num; i++) {
		cin >> w[i];
	}

	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	dp[3] = maximum(w[1] + w[3], w[2] + w[3]);

	for (i = 4; i <= num; i++) {
		dp[i] = maximum(w[i] + w[i - 1] + dp[i - 3], w[i] + dp[i - 2]);
	}

	cout << dp[num];

	return 0;
}