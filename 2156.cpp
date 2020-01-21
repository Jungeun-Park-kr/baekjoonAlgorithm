#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void maximum(int *,int, int, int);

void maximum(int *max, int a, int b, int c) {
	*max = a;
	if (*max < b) {
		*max = b;
	}
	if (*max < c) {
		*max = c;
	}
}

int main() {
	int n, *w, *DP, max=0;
	int i;

	scanf("%d", &n);
	//printf("n:%d\n\n", n);
	w = (int *)malloc(sizeof(int)*(n+1));
	DP = (int *)malloc(sizeof(int)*(n+1));

	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}

	switch (n) {
		case 1:
			printf("%d", w[1]);
			return 0;
		case 2:
			printf("%d", (w[1] + w[2]));
			return 0;
		default :
			DP[1] = w[1];
			DP[2] = w[1] + w[2];
			maximum(&max,w[1] + w[2], w[1] + w[3], w[2] + w[3]);
			DP[3] = max;
	}
	for (i = 4; i <= n; ++i) {
		maximum(&max,DP[i - 1], DP[i - 2] + w[i], DP[i - 3] + w[i - 1] + w[i]);
		DP[i] = max;
	}
	

	printf("%d", DP[n]);

	return 0;
}