#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int getNum;
	int chance = 0;
	int* DP;
	int cnt = 0; //4��¥���� �� �� �ִ��� �˻��ϴ� ����

	scanf("%d", &getNum);
	DP = (int*)calloc(getNum + 1, sizeof(int));

	DP[0] = 1;
	DP[1] = 0;
	DP[2] = 3;

	if (getNum % 2 == 0)
	{
		for (int i = 4; i <= getNum;)
		{
			DP[i] = DP[i - 2] * 3; 

			DP[i] += DP[i-4]*2;//4��¥���� ���
			if (i >= 6) {
				DP[i] += DP[i - 6] * 2;
			}
			i += 2;
		}
	}

	printf("%d", DP[getNum]);
}

/*for (int j = 4; i - j >= 0;)
			{
				DP[i] += DP[i - j] * 2;
				j += 2;
			}*/

			//	if (getNum >= 4)
			//	{
			//		//2�� ����
			//		chance += two(getNum);
			//
			//		//4�� ����(4�� ���������)
			//		if (getNum % 4 == 0)
			//			chance += four(getNum);
			//
			//		//4�� ����*2�ٴ���
			//		if(getNum>=6)
			//			chance += ;
			//
			//	}
			//	else if (getNum == 2)
			//		chance = 3;
			//	else
			//		chance = 0;
			//
			//	printf("%d", chance);
			//
			//	return 0;
			//}
			//
			////2�� ����
			//int two(int getNum)
			//{
			//	int chance = 1;
			//	for (int i = getNum / 2; i > 0; i--)
			//		chance *= 3; //3���� ���
			//	return chance;
			//}
			//
			////4�ٴ���(4�� ����϶���)
			//int four(int getNum)
			//{
			//	int chance = 1;
			//	for (int i = getNum / 4; i > 0; i--)
			//		chance *= 2; //2���� ���
			//	return chance;
			//}
			//
			//int mix(int getNum)
			//{
			//	int chance = 1;
			//	while (getNum--)
			//	{
			//		if (getNum / 6 >= 1)
			//		{
			//			if (getNum % 6 == 0)
			//			{
			//				chance *= 12;
			//				getNum -= 6;
			//			}
			//			else
			//			{
			//				if(getNum4==0)
			//			}
			//		}
			//	}
			//}