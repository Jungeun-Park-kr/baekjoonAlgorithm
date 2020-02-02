#include <iostream>
#include <limits.h>
#include <queue>
#include <utility>

using namespace std;

int minimum(int a, int b) {
	int min = a;
	if (min > b) min = b;
	return min;
}

int maximum(int a, int b) {
	int max = a;
	if (max < b) max = b;
	return max;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k, n, time, cursor;
	bool isVisited[100001] = { 0 };
	pair<int, int> current;
	queue<pair<int, int>> bfs;

	cin >> n >> k;

	bfs.push(make_pair(n, 0));
	isVisited[n] = true;
	while (1) {
		current = bfs.front();
		bfs.pop();

		if (current.first == k) {
			cout << current.second;
			break;
		}
		else {
			cursor = current.first;
			if (cursor < 100000 && !isVisited[cursor + 1]) {
				bfs.push(make_pair(cursor + 1, current.second + 1));
				isVisited[cursor] = true;
			}
			if (cursor > 0 && !isVisited[cursor - 1]) {
				bfs.push(make_pair(cursor - 1, current.second + 1));
				isVisited[cursor] = true;
			}
			if (cursor * 2 <= 100000 && !isVisited[cursor * 2]) {
				bfs.push(make_pair(cursor * 2, current.second + 1));
				isVisited[cursor] = true;
			}
		}

	}


	return 0;
}