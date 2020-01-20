#include <iostream>
#include <string>
using namespace std;

int main() {
	int input, x, y, q[5] = { 0 }, axis = 0;

	cin >> input;
	while (input--) {
		cin >> x >> y;

		if (x == 0 || y == 0)
			axis++;
		else {
			if (x > 0) {
				if (y > 0) q[1]++;
				else q[4]++;
			}
			else
				if (y > 0) q[2]++;
				else q[3]++;
		}
	}
	for (x = 1; x <= 4; x++) {
		cout << "Q" << x << ": " << q[x] << endl;
	}
	cout << "AXIS: " << axis;
	return 0;
}