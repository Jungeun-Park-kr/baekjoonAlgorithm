#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int cnt;
//vector<int> visited;
bool visited[100001];
//vector<int> v;
int v[100001];
//vector<int> checked;
bool checked[100001];



void dfs(int start) {
	if (!visited[start]) {
		visited[start] = true;

		dfs(v[start]);

		visited[start] = false;
	}
	else if (!checked[start]) {
		for (int k = start; v[k] != start; k = v[k]) {
			cnt++;
		}
		cnt++;
	}
	checked[start] = true;
}

int main() {
	int repeat, howMany, i, j, cursor, tmp;

	cin >> repeat;

	while (repeat--) {
		//입력
		cin >> howMany;
		for (i = 1; i <= howMany; i++) {
			cin >> v[i];
			visited[i] = false;
			checked[i] = false;
		}
		//검색
		cnt = 0;
		for (i = 1; i <= howMany; i++) {
			dfs(i);
		}
		//출력
		cout << howMany - cnt << '\n';
	}

	return 0;
}