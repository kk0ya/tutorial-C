//1�� �ڸ��� 7�� ���� ���� ������ ������ ���
//1~ 200���� ����

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int a, b;
	int i=0;

	while (1) {
		printf("=========================================================\n");
		printf("�� ���� �Է��ϼ��� : ");
		scanf("%d %d", &a, &b);

		if ((a >= 1 && a <= 200) && (b >= 10 && b <= 200) && (a < b)) {
			for (a; a <= b; a++) {
				if (a % 10 == 7) {
					continue;
				}
				printf("%4d", a);

				i++;

				if (i == 9) {
					printf("\n");
					i = 0;
				}
			}
		}

		else {
			printf("���α׷��� ����Ǿ����ϴ�\n");
			break;
		}
		printf("\n");
		printf("=========================================================\n");
	}
}