#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool decrease(int a, int b) {
	return a > b;
}

int main() {

	int n, p[1002], total = 0, time = 0;
	//ют╥б
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		time += p[i];
		total += time;
	}

	cout << total;

	return 0;
}