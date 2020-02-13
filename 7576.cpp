#include <iostream>
#include <queue>
#include <utility>

#define MAX 1002

using namespace std;

int warehouse[MAX][MAX];
bool visited[MAX][MAX];


queue <pair<int, int>> ripeTomato;
int day = 0;

void bfs(){
	pair <int, int> start;
	int size = ripeTomato.size();
	
	while (!ripeTomato.empty()) {
		start = ripeTomato.front();
		visited[start.first][start.second] = true;
		ripeTomato.pop();

		//next애들 구분해서 queue에 넣음
		if (warehouse[start.first][start.second + 1] == 0 && visited[start.first][start.second + 1] == false)
		{
			ripeTomato.push(make_pair(start.first, start.second + 1));
			warehouse[start.first][start.second + 1] = warehouse[start.first][start.second] + 1;
		}

		if (warehouse[start.first][start.second - 1] == 0 && visited[start.first][start.second - 1] == false)
		{
			ripeTomato.push(make_pair(start.first, start.second - 1));
			warehouse[start.first][start.second-1] = warehouse[start.first][start.second] + 1;
		}

		if (warehouse[start.first + 1][start.second] == 0 && visited[start.first + 1][start.second] == false)
		{
			ripeTomato.push(make_pair(start.first + 1, start.second));
			warehouse[start.first+1][start.second] = warehouse[start.first][start.second] + 1;
		}

		if (warehouse[start.first - 1][start.second] == 0 && visited[start.first - 1][start.second] == false)
		{
			ripeTomato.push(make_pair(start.first - 1, start.second));
			warehouse[start.first - 1][start.second] = warehouse[start.first][start.second] + 1;
		}
	}

}

int main() {
	int tmp, M, N, i, j;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			warehouse[i][j] = -2;
		}
	}

	cin >> M >> N;

	//입력
	for (i = 1; i <= N; i++) { //y축
		for (j = 1; j <= M; j++) { // x축
			cin >> tmp;
			warehouse[i][j] = tmp;
			if (tmp == 1) {
				ripeTomato.push(make_pair(i, j));
			}
		}
	}

	bfs();

	//출력
	int max = -99;
	for (i = 1; i <= N; i++) { 
		for (j = 1; j <= M; j++) {
			if (warehouse[i][j] > max) {
				max = warehouse[i][j];
			}
			if (warehouse[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << max-1;

	return 0;
}