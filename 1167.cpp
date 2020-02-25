#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100000 + 1;

vector <pair<int, int>> Tree[MAX];
bool visited[MAX];
int maxLen;
int dist;

void dfs(int start, int length) {

	if (visited[start]) {
		return;
	}
	visited[start] = true;
	if (maxLen < length) {
		dist = start;
		maxLen = length;
	}

	for (int i = 0; i < Tree[start].size(); ++i) {
		if (visited[Tree[start][i].first] == false) {
			/*if (maxLen < (length + Tree[start][i].second)) {
				maxLen = length + Tree[start][i].second;
			}*/
			dfs(Tree[start][i].first, length + Tree[start][i].second);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int howMany, vertexNum1, vertexNum2, diameter, length = 0;

	int i, j;
	cin >> howMany;



	for (i = 0; i < howMany; ++i) {
		cin >> vertexNum1 >> vertexNum2 >> diameter;

		Tree[vertexNum1].push_back({ vertexNum2,diameter });

		while (true) {
			cin >> vertexNum2;
			if (vertexNum2 != -1) {
				cin >> diameter;
				Tree[vertexNum1].push_back({ vertexNum2,diameter });
			}
			else {
				break;
			}
		}
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(dist, 0);

	cout << maxLen;

	return 0;
}