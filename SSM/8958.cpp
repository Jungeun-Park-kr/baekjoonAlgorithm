#include <iostream>
#include <string>
using namespace std;

int main() {
	int i, j, score, cnt;
	string str;
	cin >> i;

	while (i--) {
		cin >> str;
		score = 0;
		cnt = 0;
		for (j = 0; str[j] != '\0'; j++) {
			if (str[j] == 'O') {
				cnt++;
				score += cnt;
			}
			if (str[j] == 'X') {
				cnt = 0;
			}
		}

		cout << score << endl;
	}
	return 0;
}