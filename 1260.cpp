#include <iostream>
#include <utility>
#include <queue>
using namespace std;

void dfs(int start, int vertexNum, bool **bp, bool *visited) {

	visited[start] = true;
	cout << start << ' ';
	for (int j = 1; j <= vertexNum; ++j) {
		if (bp[start][j] == true && visited[j] == false) {
			dfs(j, vertexNum, bp, visited);
		}
	}
}

int main() {
	int vertexNum, edgeNum, start, t1, t2, j;
	bool **bp, *visited;
	queue <int> bfsQueue;
	
	cin >> vertexNum >> edgeNum >> start ; 

	int col = vertexNum, row=vertexNum;	 //col : 세로, row : 가로

	bp = (bool **)malloc(sizeof(bool *)*(1+row));
	for (int i = 1; i <= row; i++) {
		bp[i] = (bool *)calloc(col+1,sizeof(bool));
	}
	for (int i = 1; i <= edgeNum; i++) {
		cin >> t1 >> t2;
		bp[t1][t2] = true;
		bp[t2][t1] = true;
	}

	visited = (bool *)malloc(sizeof(bool)*(1 + vertexNum));
	for (int i = 1; i <= vertexNum; i++) {
		visited[i] = false;
	}
	

	//Depth First Search
	dfs(start,vertexNum, bp,visited);
	cout << '\n';


	for (int i = 1; i <= vertexNum; i++) {
		visited[i] = false;
	}

	//Breadth First Search
	int tmp;
	bfsQueue.push(start);
	visited[start] = true;
	while (!(bfsQueue.empty())) {
		tmp = bfsQueue.front();
		cout << tmp << ' ';
		bfsQueue.pop();
		for (j = 1; j <= vertexNum; ++j) {
			if (bp[tmp][j] == true && visited[j] == false) {
				//cout << start;
				visited[j] = true;
				bfsQueue.push(j);
			}
		}
	}
	
	return 0;
}

