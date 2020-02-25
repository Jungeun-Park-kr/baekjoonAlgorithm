#include <iostream>

using namespace std;

int all[2188][2188];
int paper[3];

int dx[9] = { 0,1,2,0,1,2,0,1,2 };
int dy[9] = { 0,0,0,1,1,1,2,2,2 };

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
		paper[num + 1] += 1;
	}
	else {
		for (int i = 0; i < 9; i++) {
			check(length / 3, y + (length / 3) * dy[i], x + (length / 3) * dx[i]);
		}
	}
}

int main() {
	int i, j, k, n;

	//입력
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> all[i][j];
		}
	}

	//for (i = 1; i <= n; i++, cout << endl) {
	//	for (j = 1; j <= n; j++) {
	//		cout << all[i][j] << ' ';
	//	}
	//}

	//재귀
	check(n, 1, 1);


	//출력
	for (i = 0; i < 3; i++) {
		cout << paper[i] << '\n';
	}
}