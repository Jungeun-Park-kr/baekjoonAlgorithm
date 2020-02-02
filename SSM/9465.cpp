#include <iostream>
#include <limits.h>
using namespace std;

int minimum(int a, int b) {
	int min = a;
	if (min > b) min = b;
	return min;
}

int maximum(int a, int b) {
	int max = a;
	if (max < b) max = b;
	return max;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k, n, input, max = 0, /*w[2][100001], dp[2][100001]*/* w[2], * dp[2];
	cin >> n;
	while (n--) {

		cin >> input;

		w[0] = (int*)calloc(input + 1, sizeof(int));
		w[1] = (int*)calloc(input + 1, sizeof(int));
		dp[0] = (int*)calloc(input + 1, sizeof(int));
		dp[1] = (int*)calloc(input + 1, sizeof(int));
		for (i = 1; i <= input; i++)
			cin >> w[0][i];
		for (i = 1; i <= input; i++)
			cin >> w[1][i];

		dp[0][1] = w[0][1];
		dp[1][1] = w[1][1];
		dp[0][2] = w[0][2] + w[1][1];
		dp[1][2] = w[1][2] + w[0][1];

		for (i = 3; i <= input; i++) {
			dp[0][i] = maximum(w[0][i] + dp[1][i - 1], w[0][i] + dp[1][i - 2]);
			dp[1][i] = maximum(w[1][i] + dp[0][i - 1], w[1][i] + dp[0][i - 2]);
		}

		cout << maximum(dp[0][input], dp[1][input]) << '\n';

		free(w[0]);
		free(w[1]);
		free(dp[0]);
		free(dp[1]);
	}
	return 0;
}