#include <iostream>

using namespace std;

int arr[301];
int numOfSet[301];

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

void findNumOfSet(int k, int n, int m) {
	int cnt = 0, total = k, set;
	bool isOkay = true;
	m--;
	set = m;
	for (int i = 0; i < n; i++) {
		if (total < arr[i]) {
			total = k;
			m--;
			numOfSet[set - m - 1] = cnt;
			cnt = 0;
		}

		total -= arr[i];
		cnt++;
	}
	set = set - m;
	numOfSet[set] = cnt;
}

int main() {
	int n, m, k = 0, min = 0, max = 0; //n = 구슬 수, m = 그룹 수
	int input, start, end, cnt = 0; // [start~end]가 범위
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i] = input;
		if (input > min) min = input;
		max += input;
	}

	//계산1 최댓값중 최솟값 찾기
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

	//계산2 그룹의 수 구하기
	findNumOfSet(k, n, m);

	//출력
	cout << k << '\n';
	for (int i = 0; i < m; i++) {
		if (numOfSet[i] == 0) cnt++;
	}
	m -= cnt;
	for (int i = 0; i < m; i++) {
		while (cnt > 0 && numOfSet[i] > 1) {
			numOfSet[i]--;
			cout << 1 << ' ';
			cnt--;
		}
		cout << numOfSet[i] << ' ';
	}
	return 0;
}