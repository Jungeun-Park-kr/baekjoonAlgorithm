#include <iostream>
#include <string>

using namespace std;

int main() {
	int i, j, numOf0[41] = { 0 }, numOf1[41]{ 0 };

	numOf0[0] = 1;
	numOf1[0] = 0;
	numOf0[1] = 0;
	numOf1[1] = 1;

	int input, n;
	cin >> n;
	while (n--) {

		cin >> input;

		for (i = 2; i <= input; i++) {
			if (numOf0[i] == 0) numOf0[i] = numOf0[i - 1] + numOf0[i - 2];
			if (numOf1[i] == 0) numOf1[i] = numOf1[i - 1] + numOf1[i - 2];
		}
		cout << numOf0[input] << " " << numOf1[input] << endl;
	}
	return 0;
}