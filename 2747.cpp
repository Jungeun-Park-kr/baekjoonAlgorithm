#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int num = 0;
	int result[46] = { 0, 1, };
	
	scanf("%d", &num);
	int i;
	for (i = 2; i <= num; i++) {
		result[i] = result[i - 2] + result[i - 1];
	}
	printf("%d",result[num]);
	
	return 0;
}