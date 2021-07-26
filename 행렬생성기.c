//행렬을 for문으로 생성
//주대각 성분만 출력

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int matrix[8][8];
	int i, k;
	int val = 1;

	for (i = 0; i < 8; i++) {
		for (k = 0; k < 8; k++) {
			matrix[i][k] = val;
			printf("%3d", matrix[i][k]);
			val++;
		}
		printf("\n");
	}

	printf("\n");

	printf("주대각 성분\n");
	for (i = 0; i < 8; i++) {
		printf("%3d",matrix[i][i]);
	}
	printf("\n");
}
