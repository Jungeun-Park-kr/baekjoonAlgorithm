#include <iostream>
#include <string>
using namespace std;

int main() {
	int num1, num2, k, sum, min;

	cin >> num1 >> num2;
	sum = 0;
	min = 0;
	for (k = 1; k <= 100; k++) {
		if (num1 <= k * k && k * k <= num2) {

			sum += k * k;

			if (min == 0) {
				min = k * k;
			}
		}
	}
	if (min == 0) cout << -1;
	else cout << sum << endl << min;

	return 0;
}