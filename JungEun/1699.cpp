#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define MIN(a,b) (a)<(b) ? (a) : (b)

int main() {
	int *dp, num;
	int i, j;
	scanf("%d", &num);
	dp = (int *)malloc(sizeof(int)*(num + 1));

	for (i = 0; i <= num; i++) {
		dp[i] = i;
	}

	for (i = 2; i <= num; i++) {
		for (j = 2; j*j <= i; j++) {
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);
		}
	}
	
	printf("%d", dp[num]);
	free(dp);
	return 0;
}