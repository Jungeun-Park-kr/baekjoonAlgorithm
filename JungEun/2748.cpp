#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
/*6번만에 제출 성공함ㅋㅋㅋㅋㅋㅋㅋ
 * long long 형식변환문자를 lld로 하지 않았다...
 * 그것도 모르고 자꾸 애먼데를 수정하기를 다섯 번...
 * 40분만에 깨.달.았.다.
 * 기본에 충실하자!! 
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
