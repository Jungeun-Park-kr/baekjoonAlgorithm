#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void dfs(int i, int* visited);

vector<int> bp[20001];

int main(void)
{
	int vertexNum, edgeNum, repeat;
	int* visited;
	int u, v;
	int cnt = 0;

	cin >> repeat;
	while (repeat--) {
		cin >> vertexNum >> edgeNum;
		visited = (int*)malloc(sizeof(int) * (vertexNum + 1));
		for (int i = 0; i <= vertexNum; i++) {
			visited[i] = false;
			bp[i].clear();
		}
		for (int i = 1; i <= edgeNum; i++)
		{
			cin >> u >> v;
			bp[u].push_back(v);
			bp[v].push_back(u);
		}
		visited[0] = true;
		for (int i = 1; i < vertexNum; i++) {
			if (visited[i] == false) {
				visited[i] = 1;
				dfs(i, visited);
			}
		}

		if (visited[0])
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		free(visited);
	}
	return 0;
}
void dfs(int i, int* visited) {
	for (int j = 0; j < bp[i].size(); j++) {
		if (visited[bp[i][j]] == false) {
			visited[bp[i][j]] = (-1) * visited[i];
			dfs(bp[i][j], visited);
		}
		else if (visited[bp[i][j]] != false) {
			if (visited[bp[i][j]] != (-1) * visited[i])
				visited[0] = false;
		}
	}
}