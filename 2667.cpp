#include <stdio.h>
#include <stdlib.h>

void dfs(int arr[27][27], bool visited[27][27], int cnt, int startCol, int startRow);

int  main(void)
{
	int howMany;
	int input;
	int cnt = 1;
	int startCol, startRow;
	int tmp;
	int include[500] = { 0 };
	scanf("%d", &howMany);
	getchar();

	int arr[27][27] = { 0 };
	bool visited[27][27] = { 0 };


	for (int i = 1; i <= howMany; i++)
	{
		for (int j = 1; j <= howMany; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
		getchar();
	}

	/*for (int i = 1; i <= howMany; i++)
	{
		for (int j = 1; j <= howMany; j++)
		{
			printf("%d", arr[i][j]);
		}
	}*/

	for (int i = 1; i <= howMany; i++)
	{
		for (int j = 1; j <= howMany; j++)
		{
			if (visited[i][j] == false && arr[i][j] == 1)
			{
				dfs(arr, visited, cnt, i, j);
				cnt++;
			}
			
		}

	}

	for (int k = 1; k < cnt; k++)
	{
		for (int i = 1; i <= howMany; i++)
		{
			for (int j = 1; j <= howMany; j++)
			{
				if (arr[i][j] == k)
					include[k] += 1;
			}
		}
	}

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = i+1; j <= cnt; j++)
		{
			if (include[i] > include[j])
			{	
				tmp = include[i];
				include[i] = include[j];
				include[j] = tmp;
			}			
		}
	}
	/*for (int i = 0; i <= cnt; i++)
		printf("%d",include[i]);*/

	printf("%d\n", cnt-1);

	for (int i = 2; i <= cnt; i++)
		printf("%d\n", include[i]);
	
	return 0;
}

void dfs(int arr[27][27], bool visited[27][27], int cnt, int startCol, int startRow)
{

	visited[startCol][startRow] = true;
	arr[startCol][startRow] = cnt;

	if (arr[startCol][startRow + 1] == 1 && visited[startCol][startRow + 1] == false)
	{
		dfs(arr, visited, cnt, startCol, startRow + 1);
	}

	if (arr[startCol][startRow - 1] == 1 && visited[startCol][startRow - 1] == false)
	{
		dfs(arr, visited, cnt, startCol, startRow - 1);
	}

	if (arr[startCol + 1][startRow] == 1 && visited[startCol + 1][startRow] == false)
	{
		dfs(arr, visited, cnt, startCol + 1, startRow);
	}

	if (arr[startCol - 1][startRow] == 1 && visited[startCol - 1][startRow] == false)
	{
		dfs(arr, visited, cnt, startCol - 1, startRow);
	}

	return;
}
