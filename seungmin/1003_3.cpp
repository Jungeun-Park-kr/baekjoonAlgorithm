#include <stdio.h>

int main(void)
{
	int arr[41][2] = {0};
	int howMany;
	int n;

	arr[0][0] = 1;
	arr[0][1] = 0;

	arr[1][0] = 0;
	arr[1][1] = 1;

	scanf("%d", &howMany);
	while (howMany--)
	{
		scanf("%d", &n);
		if (n >= 2)
		{
			for (int i = 2; i <= n; i++)
			{
				arr[i][0] = arr[i - 2][0] + arr[i - 1][0]; 
				arr[i][1] = arr[i - 2][1] + arr[i - 1][1]; 
			}
		}
			printf("%d %d\n", arr[n][0], arr[n][1]);
	}

}