//Ű�� �����Ը� �Է��ϸ� å�� ��õ���ִ� ���α׷�
//�մ��� å�� ������ ������ ��� �ݺ�


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	int height, weight;
	int price;
	char choice;
	char book[30];

	for (; ; ) {
		printf("=========================================================================\n");
		printf("�ȳ��ϼ��� �մ� �ݰ����ϴ� :)  Ű�� �����Ը� �Է��ϸ� å�� ��õ�ص����!\n");
		printf("Ű : ");
		scanf("%d", &height);
		printf("������ : ");
		scanf("%d", &weight);

		if (height >= 170) {
			if (weight >= 50) {
				price = 9000;
				strcpy(book, "��ȸ��");
			}

			else if (weight < 50) {
				price = 7000;
				strcpy(book, "�ⱸ��");
			}
		}

		else if (height < 170) {
			if (weight >= 50) {
				price = 5000;
				strcpy(book, "����ȸ��");
			}

			else if (weight < 50) {
				price = 3000;
				strcpy(book, "��������");
			}
		}

		printf("%s�� %d�� �Դϴ�. å�� ���� �Ͻðڽ��ϱ�?[y/n] : ",book,price);
		scanf(" %c", &choice);

		if (choice == 'y') {
			printf("�������ּż� �����մϴ�\n");
			break;
		}

		else {
			printf("��, �׷� �����մ�~~\n");
		}
		printf("=========================================================================\n");
	}
}