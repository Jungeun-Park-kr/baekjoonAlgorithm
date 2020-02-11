#include <iostream>
#include <utility>

using namespace std;
void dfs(int* bp, int* visited, int hope,int start);

int cnt=0;

int main(void)
{
	int howMany;
	int studentNum;
	int edgeNum;
	int* visited;
	int compare;
	int hope;
	int start;

	cin >> howMany;
	while (--howMany) 
	{
		cin >> studentNum;

		edgeNum = studentNum - 1;
		int* bp;
		bp = (int*)malloc(sizeof(int) * (studentNum + 1));
		visited = (int*)malloc(sizeof(int) * (studentNum + 1));

		for (int i = 0; i <= studentNum; i++)
			visited[i] = false;

		for (int i = 1; i <= studentNum; i++)
		{
			cin >> hope;
			bp[i] = hope;
		}


		for (int i = 1; i <= studentNum; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = true;
				start = i;
				dfs(bp, visited, bp[start], start);
			}
		}

		cout << cnt;
	}
	
	return 0;
}

void dfs(int* bp, int* visited, int hope, int root) {

	visited[hope] = true; //3은 방문 됐다
	if (bp[hope] == root) //3이 가고싶은 곳
	{
		cnt++;
	}
	else if (visited[bp[hope]] != true)
	{
		visited[bp[hope]] = true;
		dfs(bp, visited, bp[hope], root);
	}

	return;
}


