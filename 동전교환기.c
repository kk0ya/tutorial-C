//�ݾ��� �Է��ϸ� 500��, 100��, 50��, 10������ ȯ��
//500��¥���� �� �� �ʿ����� ����� �ʿ��� ��ŭ �ٲ���
//���� 500��¥���� ��ü�ݾ��� �ʰ��ϸ� ������ �ִ��� ������ �ٲ���

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int c500, c100, c50, c10;
	int money;
	
	printf("##��ȯ�� ����? : ");
	scanf("%d", &money);

	printf("##500��¥�� � �ʿ�? : ");
	scanf("%d", &c500);

	if (c500 * 500 > money) {
		printf("##��ȯ�� �ݾ����� %d�� �� �ٲ�����\n\n", c500);
		c500 = money / 500;
	}

	money = money - c500 * 500;

	c100 = money / 100;
	money = money % 100;

	c50 = money / 50;
	money = money % 50;

	c10 = money / 10;
	money = money % 10;

	printf("�����¥�� : %d��\n", c500);
	printf("���¥�� : %d��\n", c100);
	printf("���ʿ�¥�� : %d��\n", c50);
	printf("�ʿ�¥�� : %d��\n", c10);
	printf("�ٲ��� ���� �ܵ� : %d��\n",money );
}