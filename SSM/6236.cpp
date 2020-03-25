#include <iostream>

using namespace std;

int arr[100001];

bool decide(int k, int n, int m) {
	int total = k;
	bool isOkay = true;
	m--;
	for (int i = 0; i < n; i++) {
		if (total < arr[i]) {
			if (m == 0) {
				isOkay = false;
				break;
			}
			else {
				total = k;
				m--;
			}
		}
		total -= arr[i];
	}
	return isOkay;
}

int main() {
	int n, m, k = 0, min = 0, max = 0; //n = 용돈 사용 날, m = 용돈 인출 수
	int input, start, end; // [start~end]가 범위
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i] = input;
		if (input > min) min = input;
		max += input;
	}

	//계산
	start = min;
	end = max;
	int tmp;
	while (start != end) {
		tmp = (start + end) / 2;
		//cout << start << " " << end << " "<<tmp << '\n';
		if (decide(tmp, n, m)) {
			end = tmp;
		}
		else {
			start = tmp + 1;
		}
	}
	k = start;

	//출력
	cout << k;
	return 0;
}