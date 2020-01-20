#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//소요시간 : 20분
//제출 횟수 2번
//틀린 이유 : 출력에 스페이스바 하나 넣었다고 틀림^^... 다음부턴 조심해야지...,.,.,.

int whereDot(int, int);
int whereDot(int x, int y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	if (x > 0) {
		if (y > 0) {
			return 1;
		}
		else {
			return 4;
		}
	}
	else { //x음수
		if (y > 0) {
			return 2;
		}
		else {
			return 3;
		}
	}
}
int main() {
	int *point, num, x,y,i;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis=0;
	scanf("%d", &num);
	point = (int *)malloc(sizeof(int)*num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &x, &y);
		point[i] = whereDot(x, y);

		switch (point[i]) {
		case 0:
			++axis;
			break;
		case 1:
			++q1;
			break;
		case 2:
			++q2;
			break;
		case 3:
			++q3;
			break;
		case 4:
			++q4;
			break;
		}
	}
	printf("Q1: %d\n", q1);
	printf("Q2: %d\n", q2);
	printf("Q3: %d\n", q3);
	printf("Q4: %d\n",	q4);
	printf("AXIS: %d", axis);
	return 0;
}