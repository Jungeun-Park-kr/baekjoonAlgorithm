#include <iostream>

using namespace std;

int main() {
	long long n, m, cnt = 1;

	cin >> n >> m;

	if (n > 2) {
		if (m >= 7) {
			cnt += 2 + (m - 5);
		}
		else {
			cnt += (m - 1);
			if (cnt > 4) cnt = 4;
		}
	}
	else if (n == 2) {
		cnt += (m - 1) / 2;
		if (cnt > 4) cnt = 4;
	}

	cout << cnt;
	return 0;
}