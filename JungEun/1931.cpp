#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
struct Time {
	int first;
	int second;
};

bool cmp(Time iter1, Time iter2) {
	if (iter1.second == iter2.second) {
		return iter1.first < iter2.first;
	}
	else {
		return iter1.second < iter2.second;
	}

}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	int N, start, end, cnt = 0;

	cin >> N; //총 회의의 개수

	vector<Time> meeting(N);
	for (int i = 0; i < N; ++i) {
		cin >> start >> end;
		meeting[i].first = start;
		meeting[i].second = end;
	}

	sort(meeting.begin(), meeting.end(),cmp);

	start = end = 0;
	for (int i = 0; i < N; ++i) {
		start = meeting[i].first;

		if (end <= start) {
			++cnt;
			end = meeting[i].second;
		}
		
	}

	cout << cnt;
	return 0;
}