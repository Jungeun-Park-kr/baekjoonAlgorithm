#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int maximum(int a, int b) {
	int max = a;
	if (b > max) {
		max = b;
	}
	return max;
}

int main() {

	int *W, *DP, *include, num;
	int i;

	scanf("%d", &num);
	W = (int *)malloc(sizeof(int)*(num + 1));
	DP = (int *)malloc(sizeof(int)*(num + 1));
	include = (int *)malloc(sizeof(int)*(num + 1));

	for (i = 1; i <= num; i++) {
		scanf("%d", &W[i]);
	}

	include[1] = W[1];
	DP[1] = W[1];

	for (i =  2; i <= num; i++) {
		include[i] = maximum(W[i], W[i] + include[i - 1]);
		DP[i] = maximum(DP[i - 1], include[i]);

	}
	printf("%d", DP[num]);

	return 0;
}