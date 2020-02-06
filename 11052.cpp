#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main(void)
{
	int howMany;
	int getNum;
	int* DP;
	int* P;
	int max;

	scanf("%d", &howMany);


	DP = (int*)malloc(sizeof(int) * (howMany + 1));
	P = (int*)malloc(sizeof(int) * (howMany + 1));

	DP[0] = 0;

	for (int i = 1; i <= howMany; i++)
		scanf("%d", &P[i]);
	
	DP[1] = P[1];
	max = 0;
	for (int i = 2; i <= howMany; i++)
	{
		DP[i] = 0;
		for (int j = 0; j < i; j++) 
		{
			if(DP[i]<DP[j]+P[i-j])
				DP[i] = DP[j] + P[i - j];
		}
	}

		
	
	printf("%d",DP[howMany]);

	return 0;
	
}
