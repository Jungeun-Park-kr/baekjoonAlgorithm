#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> Tree[100000 + 1];

bool visited[100000 + 1];
int maxLen;
int farNode;

void dfs(int start, int length) {

	if (visited[start] == true) {
		return;
	}

	visited[start] = true;
	if (maxLen < length) {
		maxLen = length;
		farNode = start;
	}

	for (int i = 0; i < Tree[start].size(); i++) {
		dfs(Tree[start][i].first, length + Tree[start][i].second);
	}

}

int main() {
	int howMany, vertexNum1, vertexNum2, diameter, length = 0;

	int i, j;
	cin >> howMany;

	for (i = 1; i <= howMany; ++i) {
		cin >> vertexNum1;

		while (true) {
			cin >> vertexNum2;
			if (vertexNum2 != -1) {
				cin >> diameter;
				Tree[vertexNum1].push_back(make_pair(vertexNum2, diameter));
			}
			else {
				break;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	maxLen = 0;
	memset(visited, false, sizeof(visited));
	dfs(farNode, 0);

	cout << maxLen;

	return 0;
}