#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//소요시간 30분

void howFibonacci(int *, int*,int);

void howFibonacci(int *ary0, int*ary1, int n) {
	for(int i=2; i<=n; i++){
		ary0[i] = ary0[i - 2] + ary0[i - 1];
		ary1[i] = ary1[i - 2] + ary1[i - 1];
	}
}

int main() {
	int repeat, num;
	int ary0[41] = { 1,0, };
	int ary1[41] = { 0,1 };
	scanf("%d", &repeat);
	
	while (repeat--) {
		scanf("%d", &num);
		switch (num) {
		case 0:
			printf("1 0\n");
			break;
		case 1 :
			printf("0 1\n");
			break;
		default :
			howFibonacci(ary0, ary1, num);
			printf("%d %d\n", ary0[num], ary1[num]);
			break;
		}
	}
	return 0;
}