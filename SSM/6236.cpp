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
	int n, m, k = 0, min = 0, max = 0; //n = �뵷 ��� ��, m = �뵷 ���� ��
	int input, start, end; // [start~end]�� ����
	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i] = input;
		if (input > min) min = input;
		max += input;
	}

	//���
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

	//���
	cout << k;
	return 0;
}