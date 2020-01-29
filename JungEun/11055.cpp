#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int num, *W, *DP, *sum, w_sum=0;
	int i, j;
	
	scanf("%d", &num);
	
	W = (int *)malloc(sizeof(int)*(num + 1));
	sum = (int *)calloc(num + 1, sizeof(int));

	for (i = 1; i <= num; i++) {
		scanf("%d", &W[i]);
	}
	W[0] = 0;
	for (i = 1; i <= num; i++) {
		for (j = 0; j < i; j++) {
			if (W[j] < W[i]) {
				if (sum[i] < sum[j] + W[i]) {
					sum[i] = sum[j]+W[i];
				}
			}
		}

		if (w_sum < sum[i]) {
			w_sum = sum[j];
		}
	}
	printf("%d", w_sum);

	return 0;
}