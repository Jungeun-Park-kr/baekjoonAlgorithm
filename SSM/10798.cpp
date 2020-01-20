#include <iostream>
#include <string>

using namespace std;

int main() {
	char words[5][16] = { 0 };

	for (int i = 0; i < 5; i++) {
		cin >> words[i];
	}
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 5; i++) {
			if (!(words[i][j] == '\0' || words[i][j] == '\n'))
				cout << words[i][j];
		}
	}

	return 0;
}