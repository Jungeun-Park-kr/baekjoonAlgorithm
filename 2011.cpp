#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000
int main() {
	int code[5005] = { 0 };
	int DP[5005] = { 1,1,0 };
	int num = 0, i, len;
	string input;


	cin >> input;
	len = input.length();
	for (int i = 1; i <= len; i++)
	{
		code[i] = input[i - 1] - '0';
	}


	if (code[1] == 0) {
		cout << 0;
		return 0;
	}

	for (i = 2; i <= len; i++) {
		if (code[i] == 0) {
			if (code[i - 1] > 2 || code[i - 1] < 1) {
				cout << 0;
				return 0;
			}
		}
		else {
			DP[i] += DP[i - 1] % MOD;
		}
		if (code[i - 1] == 2) {
			if (code[i] <= 6)
				DP[i] += DP[i - 2] % MOD;
		}
		else if (code[i - 1] == 1) {
			DP[i] += DP[i - 2] % MOD;
		}
	}

	cout << DP[i - 1] % MOD;

	return 0;
}