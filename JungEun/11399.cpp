#include <iostream>
#include <algorithm>

using namespace std;
int * atm_line;
int main() {
	int N, tmp, total=0;
	cin >> N;

	atm_line = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		atm_line[i] = tmp;
	}

	sort(atm_line, atm_line+N);
	
	tmp = 0;
	for (int i = 0; i < N; ++i) {
		tmp += atm_line[i];
		total += tmp;
	}
	cout << total;

	return 0;
}