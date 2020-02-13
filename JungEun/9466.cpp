#include <iostream>
#define MAX 1000001
using namespace std;

bool visited[MAX];
bool team[MAX];
int S[MAX];
int cnt;

void dfs(int num) {
	int next = S[num];
	visited[num] = true;

	if (visited[next]) {
		if (team[next] == false) {
			for (int i = next; i != num; i = S[i]) {
				++cnt;
			}
			++cnt;
		}
	}
	else {
		dfs(next);
	}
	team[num] = true;

	return;
}
int main() {
	int T, r, tmp, sum = 0, result=0;
	bool isAlone = false;
	cin >> T;//TC수

	while (T--) {
		
		cin >> r; //학생 수

		for (int i = 1; i <= r; ++i) {
			cin >> tmp;
			S[i] = tmp;
		}

		for (int i = 1; i <= r; ++i) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
		cout << (r-cnt) << '\n';

		//초기화
		for (int i = 1; i <= r; ++i) {
			visited[i] = false;
			S[i] = 0;
			team[i] = false;
		}
		cnt = 0;
	}

	return 0;
}