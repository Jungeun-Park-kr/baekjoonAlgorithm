#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
/*6腰幻拭 薦窒 失因敗せせせせせせせ
 * long long 莫縦痕発庚切研 lld稽 馬走 省紹陥...
 * 益依亀 乞牽壱 切荷 蕉胡汽研 呪舛馬奄研 陥叱 腰...
 * 40歳幻拭 凹.含.紹.陥.
 * 奄沙拭 中叔馬切!! 
*/
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
