//����� for������ ����
//�ִ밢 ���и� ���

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
			val++;
		}
	}

	//��� ���
	for (i = 0; i < 8; i++) {
		for (k = 0; k < 8; k++) {
			printf("%3d",matrix[i][k]);
		}
		printf("\n");
	}
	printf("\n");

	printf("�ִ밢 ����\n");
	for (i = 0; i < 8; i++) {
		for (k = 0; k < 8; k++) {
			if (i == k) {
				printf("%3d",matrix[i][k]);
			}
		}
	}
	printf("\n");
}