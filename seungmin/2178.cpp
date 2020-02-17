#include <stdio.h>
#define MAX 102

int N, M;
int rtnCnt=999;



void dfs(int map[MAX][MAX], bool visited[MAX][MAX], int cnt, int startCol, int startRow)
{
	int priority=0;
	
	visited[startCol][startRow] = true;

	if (map[startCol][startRow + 1] == 1 && visited[startCol][startRow + 1] == false)//����������
	{
		priority = 1;
		cnt++;
		
		//printf("���������� %d\n", cnt);
		dfs(map, visited, cnt, startCol, startRow + 1);
		cnt--;
	}
	if(map[startCol + 1][startRow] == 1 && visited[startCol + 1][startRow] == false)//����
	{
		priority = 1;
		cnt++;
		//printf("�Ʒ������� %d\n", cnt);
		dfs(map, visited, cnt, startCol + 1, startRow);
		cnt--;
	}
	if (priority == 0 && (map[startCol-1][startRow]==1 && visited[startCol-1][startRow]==false))//������, ���� ������ ��Ȳ
	{
		cnt++;
		//printf("�������� %d\n", cnt);
		dfs(map, visited, cnt, startCol-1, startRow);
		cnt--;
	}

	if (startCol == N && startRow == M)
	{
		if (cnt < rtnCnt)
			rtnCnt = cnt;
	}
	visited[startCol][startRow + 1] = false;
	visited[startCol +1][startRow] = false;
	visited[startCol - 1][startRow] = false;
	visited[startCol][startRow-1] = false;


	return;
}

int main() {
	int howMany, i, j, cursor, tmp, cnt;
	int min = 9999;
	int map[102][102] = { 0 };
	bool visited[102][102] = { 0 };
	while (true) {
		scanf("%d %d", &N, &M);//hN

		if (M == 0 && N == 0)
			break;
		cnt = 1;

		//�Է�
		for (i = 1; i <= N; i++) { //y��
			for (j = 1; j <= M; j++) { // x��
				scanf("%1d", &map[i][j]);
			}
			getchar();
		}

		//�˻�
		dfs(map, visited, cnt, 1, 1);
			

		printf("%d", rtnCnt);

			
	}
	return 0;
}