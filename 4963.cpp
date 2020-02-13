#include <iostream>
#include <cstring>

using namespace std;

void dfs(int arr[52][52], bool visited[52][52], int cnt, int startCol, int startRow)
{
	visited[startCol][startRow] = true;
	arr[startCol][startRow] = cnt;
	//한번 해봄
	for (int i = startCol - 1; i <= startCol + 1; i++) {
		for (int j = startRow - 1; j <= startRow + 1; j++) {
			if (i == startCol && j == startRow) continue;
			if (arr[i][j] == 1 && visited[i][j] == false) {
				dfs(arr, visited, cnt, i, j);
			}
		}
	}

	return;
}

int main() {
	int repeat, howMany, i, j, cursor, tmp, cnt;
	int w, h;
	int map[52][52] = { 0 };
	bool visited[52][52] = { 0 };
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		cnt = 0;

		//입력
		for (i = 1; i <= h; i++) { //y축
			for (j = 1; j <= w; j++) { // x축
				cin >> map[i][j];
			}
		}

		//검색
		for (i = 1; i <= h; i++) { //y축
			for (j = 1; j <= w; j++) { // x축
				if (!visited[i][j] && map[i][j] == 1) {
					cnt++;
					dfs(map, visited, cnt, i, j);
				}
			}
		}

		//출력
		cout << cnt << '\n';

		//초기화
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}