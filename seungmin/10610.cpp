#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int sum = 0;
	int num[10] = { 0 }; //해당 인덱스의 숫자 개수
	int i, j;
	char c;
	int tmp2 = 0;

	while (1) {
		c = getchar();
		if (c == '\n') {
			break;
		}
		else {
			tmp2 = (c - '0');
			num[tmp2]++;
		}
	}

	if (num[0] > 0) {
		for (i = 0; i < 10; i++) {
			sum = sum + (num[i] * i);
		}
		if (sum % 3 == 0) {
			for (int i = 9; i >= 0; i--) {
				for (j = num[i]; j > 0; j--) {
					cout << i;
				}
			}
			return 0;
		}
		else {
			cout << -1<<'\n';
			return 0;
		}

	}
	else {
		cout << -1 << '\n';
		return 0;
	}


	return 0;
}