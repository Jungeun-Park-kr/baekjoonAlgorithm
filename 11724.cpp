#include <iostream>
#include <utility>

using namespace std;

void dfs(int i, int vertexNum, bool** bp, int* visited);

int main(void)
{
	int vertexNum, edgeNum;
	int *visited;
	int u, v;
	int cnt=0;
	int compare;
	
	cin >> vertexNum >> edgeNum;

	bool** bp;
	bp = (bool**)malloc(sizeof(bool*) * (vertexNum + 1));
	visited = (int*)malloc(sizeof(int) * (vertexNum + 1));

	for (int i = 0; i <= vertexNum; i++)
		visited[i] = false;


	for (int i = 1; i <= vertexNum; i++)
	{
		bp[i] = (bool*)calloc(vertexNum + 1, sizeof(bool));
	}

	for (int i = 1; i <= edgeNum; i++)
	{
		cin >> u >> v;
		bp[u][v] = true;
		bp[v][u] = true;
	}

	for (int i = 1; i <= vertexNum; i++)
	{
		if (visited[i] == 0) 
		{
			visited[i] = i;
			dfs(i, vertexNum, bp, visited);
		}
	}

	for (int i = 1; i <= vertexNum; i++)
	{
		if (visited[i] == i)
			cnt++;
	}

	cout << cnt;

	return 0;
}

void dfs(int i, int vertexNum, bool** bp, int* visited) {

	
	for (int j = 1; j <= vertexNum; ++j) {
		if (bp[i][j] == true && visited[j] == false) {
			visited[j] = visited[i];
			dfs(j, vertexNum, bp, visited);
		}
	}

}

