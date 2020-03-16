#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int **roller;

int main() {
	int R, C, min_i, min_j,min_val=1001;
	cin >> R >> C;

	roller = new int *[R];
	for (int i = 0; i < R; ++i) {
		roller[i] = new int[C];
		memset(roller[i], 0, sizeof(int)*C);
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> roller[i][j];
			
		}
	}
	/*if (i % 2 == 1 && j % 2 == 0) {
		min_val = min(min_val, roller[i][j]);
	}
	else if (i % 2 == 0 && j % 2 == 1) {
		min_val = min(min_val, roller[i][j]);
	}*/
	for (int i = 0; i < R; i += 2) {
		for (int j = 1; j < C; j += 2) {
			if (roller[i][j] < min_val) {
				min_val = roller[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}
	for (int i = 1; i < R; i += 2) {
		for (int j = 0; j < C; j += 2) {
			if (roller[i][j] < min_val) {
				min_val = roller[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}



	if (R % 2 == 1) { //È¦È¦, È¦Â¦
		for (int i = 1; i < R; ++i) {
			if (i % 2 == 1) {
				for (int j = 1; j < C; ++j) {
					cout << 'D';
				}
			}
			else {
				for (int j = 1; j < C; ++j) {
					cout << 'U';
				}
			}
			cout << 'R';
		}

		for (int j = 1; j < C; ++j) {
			cout << 'D';
		}
	}
	else {
		if (C % 2 == 0) { //Â¦Â¦ (Á¦ÀÏ ¾î·Á¿ò)



		}
		else { //Â¦È¦
			for (int i = 1; i < C; ++i) {
				if (i % 2 == 1) {
					for (int j = 1; j < R; ++j) {
						cout << 'R';
					}
				}
				else {
					for (int j = 1; j < R; ++j) {
						cout << 'L';
					}
				}
				cout << 'D';
			}
			for (int j = 1; j < R; ++j) {
				cout << 'R';
			}
		}
	}
	

	for (int i = 0; i < R; ++i) {
		delete[] roller[i];
	}
	delete[] roller;

	return 0;
}