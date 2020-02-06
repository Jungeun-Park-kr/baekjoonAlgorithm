#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int howMany;
	int getNum;
	long long *DP;

	scanf("%d", &howMany);

	while (howMany--)
	{
		scanf("%d", &getNum);
		DP = (long long *)calloc(getNum+1,sizeof(long long));

		switch (getNum)
		{
		case 1:
			DP[1] = 1;
			break;
		case 2:
			DP[2] = 1;
			break;
		case 3:
			DP[3] = 1;
			break;
		case 4:
			DP[4] = 2;
			break;
		case 5:
			DP[5] = 2;
			break;
		default:
			DP[1] = 1;
			DP[2] = 1;
			DP[3] = 1;
			DP[4] = 2;
			DP[5] = 2;
			break;
		}

		
		for (int i = 6; i <= getNum; i++)
			DP[i] = DP[i - 1] + DP[i - 5];
		
		printf("%lld\n",DP[getNum]);
		
		free(DP);
	}
	return 0;
}