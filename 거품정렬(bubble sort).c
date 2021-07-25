//�����͸� �̿��� ��ǰ����(bubble sort)
//�������� �������� ����

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	int s[10];
	int tmp;
	int i, k;
	int up_down;
	int* p;

	printf("\t< 0���� 9 ������ ���ڸ� �� ������ �Է����ּ��� >\n");

	//������ �Է�
	for (i = 0; i < 10; i++) {
		printf(" s[%d] ������ : ", i);
		scanf("%d", &s[i]);

		//0~9�� ���ڸ� �Է�
		if ((s[i] < 0) || (s[i] > 9)) {
			printf("\n ��0���� 9 ������ ���ڸ� �Է����ּ���\n");
			i--;
		}
		
		//�ߺ��Ǵ� ���� ����
		for (k = i-1; k >= 0; k--) {
			if (s[i] == s[k]) {
				printf("\n ���ߺ��Ǵ� ����( %d )�� �ֽ��ϴ�. �ٽ� �Է����ּ���\n",s[i]);
				i--;
			}
		}
	}

	p = s;

	//���� �� �迭
	printf("\n\t���� �� �迭 s ==> ");
	for (i = 0; i < 10; i++) {
		printf("%2d", *(p + i));
	}
	
	//���� ��� ����
	do {
		printf("\n\n ���� ����� �����ϼ��� - �������� < 1 >  �������� < 2 > \n");
		printf(" ������ ���� : ");
		scanf("%d", &up_down);

		switch (up_down) {
		case 1: //��������
			for (i = 0; i < 9; i++) {
				for (k = i + 1; k < 10; k++) {
					if (*(p + i) > *(p + k)) {
						tmp = *(p + i);
						*(p + i) = *(p + k);
						*(p + k) = tmp;
					}
				}
			}
			break;

		case 2: //��������
			for (i = 0; i < 9; i++) {
				for (k = i + 1; k < 10; k++) {
					if (*(p + i) < *(p + k)) {
						tmp = *(p + i);
						*(p + i) = *(p + k);
						*(p + k) = tmp;
					}
				}
			}
			break;
		default:
			printf("\n1 �Ǵ� 2�� �Է����ּ���!\n");
		}
	} while (up_down > 2);

	//���� �� �迭
	printf("\n\t���� �� �迭 s ==> ");
	for (i = 0; i < 10; i++) {
		printf("%2d", *(p + i));
	}
	printf("\n");
}