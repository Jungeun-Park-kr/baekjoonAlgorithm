#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int num, *DP, *W, max = 0, min;
	int i, j, k;
	scanf("%d", &num);

	DP = (int *)calloc(num + 1, sizeof(int));
	W = (int *)malloc(sizeof(int)*(num + 1));

	for (i = 1; i <= num; i++) {
		scanf("%d", &W[i]);
	}
	W[0] = 0;
	for (i = 1; i <= num; i++) {
		min = 0;
		//DP[i] = 1;
		for (j = 0; j < i; j++) {
			if (W[j]<W[i]) {
				if (min < DP[j]) {
					min = DP[j];
				}
				DP[i] = DP[j] + 1;
			}
		}
		DP[i] = min + 1;
		if (max < DP[j]) {
			max = DP[j];
		}
	}
	printf("%d", max);

	return 0;
}