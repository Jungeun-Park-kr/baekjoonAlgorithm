#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int num;
	long long *fib;

	scanf("%d", &num);
	fib = (long long  *)malloc(sizeof(long long)*(num+1));
	fib[0] = 0; fib[1] = 1;
	if (num <= 1) {
		printf("%lld", fib[num]);
	}
	else {
		for (int i = 2; i <= num; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		printf("%lld", fib[num]);
	}

	return 0;
}