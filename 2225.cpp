#include <iostream>

using namespace std;
int main() {
	int i, j, s, n, k;
	long long sum = 0, dp[201][201] = { 0 };
	//					         n,i  k,j
	cin >> n >> k;

	for (i = 0; i <= k; i++) {
		dp[1][i] = i;
		dp[0][i] = 1;
	}

	for (i = 0; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][0] = 1;
	}



	if (n == 1 || k == 1) {
		cout << dp[n][k];
	}
	else {
		for (i = 2; i <= n; i++) {
			for (j = 2; j <= k; j++) {
				sum = 0;
				for (s = 0; s <= i; s++) {
					sum += dp[s][j - 1];
				}
				dp[i][j] = sum % 1000000000;//dp[i][j-1] + dp[i-1][j-1] + dp[i-2][j-1] +...
			}
		}

		sum = 0;
		for (i = 0; i <= n; i++) {
			sum += dp[i][k - 1];
		}
		cout << sum % 1000000000;
	}

	return 0;

	/*for (i = 1;i<=k;i++) {
		dp[1][i] = i;
	}

	for (i = 0; i <= n;i++) {
		dp[i][1] = 1;
	}

	for (i=2;i<=n;i++) {
		for (j = 2;j<k; j++) {
			sum = 0;
			for (s = 0; s <= j; s++) {
				sum += dp[s][j-1];
			}
			dp[i][j] = sum;
		}
	}

	sum = 0;
	for (i=0;i<=n;i++) {
		sum += dp[i][k-1];
	}
	cout << sum;*/
}