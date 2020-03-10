#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> meet[100002];

bool cmpSecond(pair<int, int> a, pair<int, int> b) {
	bool result;

	if (a.second == b.second) {
		result = a.first < b.first;
	}
	else {
		result = a.second < b.second;
	}
	return result;
}

int main() {
	int n, start, end, cursor, cnt = 0;
	//�Է�
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		meet[i] = make_pair(start, end);
	}

	// ȸ������ �ð��� ���� ����
	sort(meet + 0, meet + n, cmpSecond);

	//�����
	/*for (int i = 0; i < n; i++) {
		cout << meet[i].first << ' ' << meet[i].second << '\n';
	}*/

	start = 0;
	end = 0;
	cursor = 0;
	while (cursor < n) {
		if (meet[cursor].first >= end) {
			cnt++;
			end = meet[cursor].second;
			/*cout << end <<'\n';*/
		}
		cursor++;
	}

	cout << cnt;
	return 0;
}