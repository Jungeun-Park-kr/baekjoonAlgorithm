#include <iostream>
#include <utility>

using namespace std;
void dfs(int* bp, bool* visited, bool* team, int hope, int start, int check);


int main(void)
{
	int howMany;
	int studentNum;
	int compare;
	int hope;
	int start;
	int check=0;
	int cnt = 0;

	cin >> howMany;
	while (--howMany) 
	{
		cin >> studentNum;

		int *bp;
		bool *visited;
		bool *team;
		bp = (int *)malloc(sizeof(int) * (studentNum + 1));
		visited = (bool *)malloc(sizeof(bool) * (studentNum + 1));
		team = (bool *)malloc(sizeof(bool) * (studentNum + 1));

		for (int i = 0; i <= studentNum; i++)
			visited[i] = false;

		for (int i = 0; i <= studentNum; i++)
			team[i] = false;

		for (int i = 1; i <= studentNum; i++)
		{
			cin >> hope;
			bp[i] = hope;
		}

		cout << "\n";


		for (int i = 1; i <= studentNum; i++)
		{
			if (visited[i] == 0) //검사되지 않은 애들만
			{
				visited[i] = true;
				start = i;
				dfs(bp, visited, team, bp[start], start,check);
				for (int i = 1; i <= studentNum; i++)
				{
				cout << team[i];
				cout << "\n";
				}
			}
		}
		

		for (int i = 1; i <= studentNum; i++) 
		{
			if (team[i] == true)
				cnt++;
		}
			

		cout << cnt;
	}
	
	return 0;
}

void dfs(int* bp, bool *visited, bool *team, int hope, int start,int check) {

	if (visited[hope] != true) 
	{
		visited[hope] = true; //3은 방문 됐다
		if (bp[hope] == start) //3이 가고싶은 곳
		{
			bp[hope] = true;
			check = 1;
			team[bp[hope]] = true;

			return ;
		}
		else if (visited[bp[hope]] != true)
		{
			visited[bp[hope]] = true;
			dfs(bp, visited, team, bp[hope], start,check);
			if (check == 1) 
			{
				team[hope] = true;
			}
				
		}
	}
	
	return;
}


