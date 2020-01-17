//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//int input(char*);
//int calcScore(char *,int);
//
//int calcScore(char *ary,int size) {
//	//printf("size : %d\n", size);
//	int tmp=0,score=0;
//	int i;
//	for (i = 0; i < size; ++i) {
//		
//		if (ary[i] == 'O') {
//			score += ++tmp;
//			//printf("tmp =%d   score =%d\n", tmp, score);
//		}
//		else {
//			if (tmp != 0) {
//				tmp = 0;
//			}
//		}
//	}
//	return score;
//}
//
//int input(char *ary) {
//	int i;
//	for (i = 0; i<80; ++i) {
//		ary[i] = getchar();
//		if (ary[i] == '\n') {
//			return i;
//		}
//	}
//	
//}
//int main() {
//	int num,size;
//	int *score;
//	scanf("%d", &num);
//	score = (int *)malloc(sizeof(int)*num);
//	getchar();
//
//	for (int i = 0; i < num; i++) {
//		char ary[80];
//		size=input(ary);
//		score[i]=calcScore(ary,size);
//	}
//	for (int i = 0; i < num; i++) {
//		printf("%d\n", score[i]);
//	}
//
//	free(score);
//	return 0;
//
//}