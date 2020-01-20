#include <stdio.h>

int fibonacci(int n, int* cnt0, int* cnt1);

int main(void)
{
	int num;
	int howMany;
	int cnt0 = 0;
	int cnt1 = 0;

	scanf("%d", &howMany);

	for (int i = 0; i < howMany; i++)
	{
		num = 0;
		cnt0 = 0;
		cnt1 = 0;
		scanf("%d", &num);
		fibonacci(num, &cnt0, &cnt1);
		printf("%d %d\n", cnt0, cnt1);
	}

	return 0;
}

int fibonacci(int n, int* cnt0, int* cnt1) {
	int num1 = n - 1;
	int num2 = n - 2;

	//printf("cnt0:%d, cnt1:%d\n", *cnt0, *cnt1);
	if (n == 0) {
		//printf("0");
		(*cnt0)++;
		return 0;
	}
	else if (n == 1) {
		(*cnt1)++;
		//printf("1");
		return 1;
	}
	else {
		return fibonacci(num1, cnt0, cnt1) + fibonacci(num2, cnt0, cnt1);
	}
}