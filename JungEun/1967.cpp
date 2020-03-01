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
			dfs(Tree[start][i].first, length + Tree[start][i].second);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int howMany, parent, child, weight, length = 0;

	int i, j;
	cin >> howMany;



	for (i = 1; i < howMany; ++i) {
		cin >> parent >> child >> weight;

		Tree[parent].push_back(make_pair(child, weight));
		Tree[child].push_back(make_pair(parent, weight));

	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(dist, 0);

	cout << maxLen;

	return 0;
}