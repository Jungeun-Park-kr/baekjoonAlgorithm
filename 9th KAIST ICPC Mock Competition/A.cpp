#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int card[501][501];

int main() {
	int n, m, cnt = 0, isSemetry = true;
	string input;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = m; j > 0; j--) {
			card[i][j] = input.at(j - 1) - '0';
		}
	}
	int ii, ij;
	//check
	for (int i = 1; i <= n - n / 2; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == n / 2 + 1 && j > m - m / 2) {
				break;
			}
			ii = n + 1 - i;
			ij = m + 1 - j;
			//cout << i << j << ii << ij << '\n';
			switch (card[i][j]) {
			case 6:
				if ((i == ii && j == ij)) {
					isSemetry = false;
					break;
				}
				if (card[ii][ij] == 6) {
					cnt++;
					break;
				}
				else if (card[ii][ij] == 9) {
					break;
				}
				isSemetry = false;
				break;
			case 7:
				if ((i == ii && j == ij)) {
					isSemetry = false;
					break;
				}
				else if (card[ii][ij] == 7) {
					cnt++;
					break;
				}
				isSemetry = false;
				break;
			case 8:
				if (card[ii][ij] == 8) {
					break;
				}
				isSemetry = false;
				break;
			case 9:
				if ((i == ii && j == ij)) {
					isSemetry = false;
					break;
				}
				if (card[ii][ij] == 9) {
					cnt++;
					break;
				}
				else if (card[ii][ij] == 6) {
					break;
				}
				isSemetry = false;
				break;
			}
			if (!isSemetry) break;
		}
		if (!isSemetry) break;
	}

	if (isSemetry) cout << cnt;
	else cout << -1;
	return 0;
}