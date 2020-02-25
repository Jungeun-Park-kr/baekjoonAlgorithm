#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int length, maxLength = 1000000, region;

queue<pair<int, int>> node;
int map[102][102];
bool visited[102][102];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int howmany;

void regionalize() {

	int nexty, nextx;
	pair<int, int> now;

	while (!node.empty()) {
		now = node.front();
		node.pop();

		for (int i = 0; i < 4; i++) {
			nexty = now.first + dy[i];
			nextx = now.second + dx[i];

			if (map[nexty][nextx] == 1 && visited[nexty][nextx] == false) {
				map[nexty][nextx] = region;
				visited[nexty][nextx] = true;
				node.push(make_pair(nexty, nextx));
			}
		}
	}
}

void bfs() {
	int size, nexty, nextx;
	pair<int, int> now;
	bool isfinded = false;
	while (!node.empty()) {

		size = node.size();
		for (int i = 0; i < size; i++) {
			now = node.front();
			node.pop();
			for (int i = 0; i < 4; i++) {
				nexty = now.first + dy[i];
				nextx = now.second + dx[i];
				if (nexty > 0 && nextx > 0 && nextx <= howmany && nexty <= howmany) {
					if (visited[nexty][nextx] == false) {
						if (map[nexty][nextx] == 0) {
							node.push(make_pair(nexty, nextx));
							visited[nexty][nextx] = true;
						}
						else {
							if (length < maxLength) maxLength = length;
							return;
						}
					}
				}
			}
		}
		length++;
	}
}

int main() {
	int i, j, k;


	//input
	cin >> howmany;
	for (i = 1; i <= howmany; i++) {
		for (j = 1; j <= howmany; j++) {
			cin >> map[i][j];
		}
	}
	//regionalize
	for (i = 1; i <= howmany; i++) {
		for (j = 1; j <= howmany; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				map[i][j] = ++region;
				visited[i][j] = true;
				node.push(make_pair(i, j));
				regionalize();
			}
		}
	}

	////debug
	//for (i = 1; i <= howmany; i++, cout << '\n') {
	//	for (j = 1; j <= howmany; j++) {
	//		cout << map[i][j];
	//	}
	//}

	//search
	for (k = 1; k <= region; k++) {
		memset(visited, false, sizeof(visited));
		while (!node.empty()) node.pop();
		length = 0;

		for (i = 1; i <= howmany; i++) {
			for (j = 1; j <= howmany; j++) {
				if (map[i][j] == k) {
					visited[i][j] = true;
					node.push(make_pair(i, j));
					/*cout << k << ' ';*/
				}
			}
		}

		bfs();

	}

	//output
	cout << maxLength;
	return 0;
}