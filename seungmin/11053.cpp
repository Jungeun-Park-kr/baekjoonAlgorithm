#include <stdio.h>
#include <stdlib.h>

int input(void);

int main(void)
{
	int max;
	int howMany;
	int* W;
	int* DP;
	int index;
	int result=0;

	howMany = input();
	W = (int *)malloc(sizeof(int) * howMany);
	DP = (int *)malloc(sizeof(int) * howMany);

	//�迭 ����
	for (int i = 0; i < howMany; i++)
		W[i]=input();

	//DP ����
	DP[0] = 1;
	for (int i = 1; i < howMany; i++)
	{
		max = 0;
		index = i;
		for (int j = 0; j < i; j++)
		{
			if (W[j] < W[i]) { //�˻� �� �ڽź��� ���� ���� �˻�
				if (max <= W[j])
				{
					index = j;
					max = W[j];
				}
			}
		}
		if (index == i) //���� ���� �������
			DP[i] = 1;
		else
			DP[i] = DP[index] + 1;
	}

	for (int i = 1; i < howMany; i++)
	{
		if (DP[i] > result)
			result = DP[i];
	}
	printf("%d", result);

	return 0;
}

int input(void)
{
	int getNum;
	scanf("%d", &getNum);
	return getNum;
}