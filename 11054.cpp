#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int num, *W,  max = 0, min;
	int i, j;
	int maxIncr=0, maxDec=0, maxMix=0, result=0;
	scanf("%d", &num);
	int *DPL, *DPR;

	DPL = (int *)calloc(num + 1, sizeof(int));
	DPR = (int *)calloc(num + 1, sizeof(int));

	W = (int *)malloc(sizeof(int)*(num + 1));

	for (i = 1; i <= num; i++) {
		scanf("%d", &W[i]);
	}
	W[0] = 0;
	for (i = 1; i <= num; i++) {
		min = 0;
		for (j = 0; j < i; j++) {
			if (W[j] < W[i]) {
				if (min < DPL[j]) {
					min = DPL[j];
				}
				DPL[i] = DPL[j] + 1;
			}
		}
		DPL[i] = min + 1;
		if (maxIncr < DPL[j]) {
			maxIncr = DPL[j];
		}
	}

	for (i = num; i >= 1; i--) {
		min = 0;
		for (j = num; j > i; j--) {
			if (W[j] < W[i]) {
				if (min < DPR[j]) {
					min = DPR[j];
				}
				DPR[i] = DPR[j] + 1;
			}
		}
		DPR[i] = min + 1;
		if (maxDec < DPR[j]) {
			maxDec = DPR[j];
		}
	}

	for (int i = 1; i <= num; i++)
			{
				if (maxMix < DPR[i] + DPL[i])
					maxMix = DPR[i] + DPL[i];
			}

	maxMix -= 1;

	result = maxIncr;
	if (result < maxDec) {
		result = maxDec;
	}
	if (result < maxMix) {
		result = maxMix;
	}

	printf("%d", result);

	return 0;
}