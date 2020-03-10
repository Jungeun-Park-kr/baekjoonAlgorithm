#include<iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	switch (N) {
	case 1:
		cout << 1;
		return 0;
	case 2:
		if (M < 3) {
			cout << 1;
			return 0;
		}
		else if (3 <= M && M <= 6) {
			if (M < 5) {
				cout << 2;
				return 0;
			}
			else {
				cout << 3;
				return 0;
			}
		}
		else { //7ÀÌ»ף
			cout << 4;
			return 0;
		}
	default:
		if (M == 1) {
			cout << 1;
			return 0;
		}
		else if (M <= 3) {
			cout << M;
			return 0;
		}
		else if (M <= 6) {
			cout << 4;
			return 0;
		}
		else {
			cout << (M - 2);
			return 0;
		}
	}
	return 0;
}