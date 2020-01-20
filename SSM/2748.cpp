#include <iostream>
#include <string>
using namespace std;

int main() {
	long long input, i, j, pibo[91];

	cin >> input;
	pibo[0] = 0;
	pibo[1] = 1;
	for (i = 2; i <= input; i++) {
		pibo[i] = pibo[i - 1] + pibo[i - 2];
	}
	cout << pibo[input];
	return 0;
}