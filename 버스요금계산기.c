//��������� ������ִ� ���α׷�
//��� : � 1200��, ��� 1000��
//ī���ܾ��� �� �������� �ݺ�

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int card_money;
	int adult = 1200, kid = 1000;
	int sum;

	printf("������� ��� ���α׷��Դϴ�\n");
	printf("��� %d��, ��̴� %d���Դϴ�\n\n", adult, kid);

	printf("���� ī���ܾ��� �Է��ϼ��� : ");
	scanf("%d", &card_money);
	
	while (1) {
		int adult_num, kid_num;

		printf("�, ���̰� �� ���̳� ž���ϳ���? : ");
		scanf("%d %d", &adult_num, &kid_num);

		sum = (adult_num * adult) + (kid_num * kid);

		if (sum <= card_money) {
			card_money -= sum;
			printf("� : %d��, ���� : %d��\n", adult_num, kid_num);
			printf("��� : %d��, ���� �ܾ� : %d\n\n", sum, card_money);
		}

		else {			
			printf("� : %d��, ���� : %d��\n", adult_num, kid_num);
			printf("����� %d�� �����մϴ�\n",sum-card_money);
			printf("���α׷��� �����մϴ�\n");
			break;
		}
	}
}