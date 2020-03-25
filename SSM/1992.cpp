#include <iostream>
#include <stdio.h>

using namespace std;

int all[65][65];

int dx[4] = { 0,1,0,1 };
int dy[4] = { 0,0,1,1 };

void check(int length, int y, int x) {
	bool isSame = true;
	int num = all[y][x];
	for (int i = y; i < y + length; i++) {
		for (int j = x; j < x + length; j++) {
			if (all[i][j] != num) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}


	if (isSame) {//다같음
		cout << num;
	}
	else {
		cout << '(';
		for (int i = 0; i < 4; i++) {
			check(length / 2, y + (length / 2) * dy[i], x + (length / 2) * dx[i]);
		}
		cout << ')';
	}
}

int main() {
	int i, j, k, n;

	//입력
	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &all[i][j]);
		}
	}

	//재귀
	check(n, 1, 1);

}