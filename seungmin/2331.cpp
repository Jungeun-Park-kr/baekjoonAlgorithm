#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiple(int getNum, int getP);
int main(void)
{
	int getA;
	int getP;
	int size = 3;
	int* DP;
	int k = 2;
	int i;
	int escape = 0;

	scanf("%d %d", &getA, &getP);
	DP = (int*)malloc(sizeof(int) * size);

	DP[0] = 0;
	DP[1] = getA;
	DP[k] = multiple(DP[k - 1], getP);
	//printf("DP[2]:%d ", DP[2]);

	while (true) 
	{
		for (i = 1; i<size-1; i++)
		{
			if (DP[k] == DP[i])
			{
				printf("%d", i - 1);
				escape = 1;
				break;
			}
		}
		
		if (escape == 1)
			break;

		size++;
		k++;
		DP = (int*)realloc(DP, sizeof(int) * size);
		/*if (DP == NULL)
			printf("NULL\0");*/
		DP[k] = multiple(DP[k - 1], getP);
		//printf("DP[%d]:%d ", k, DP[k]);
	}

	return 0;
}


int multiple(int getNum, int getP) 
{
	int scalar[7] = { 0 };
	int tmp;
	int num = 0;
	int i = 10;
	int index = 1;
	int mul;

	while (true) {
		tmp = getNum / 10; 

		if (tmp == 0)
			break;

		scalar[index] = getNum - tmp * 10; 
		getNum -= scalar[index]; 

		mul = scalar[index]; 
		for (int j = 1; j < getP; j++)
			mul *= scalar[index];

		scalar[index] = mul;
		num += scalar[index];
		index++;
		getNum /= 10; 
	}
	scalar[index] = getNum; 
	mul = scalar[index];
	for (int j = 1; j < getP; j++)
		mul *= scalar[index];
	scalar[index] = mul;
	num += scalar[index];

	return num;
}