//Ư�����ڸ� �ٸ����ڷ� ��ȯ �� ��ü���ڸ� ��ҹ��� ��ȯ

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	char input[100];
	char old, new;
	int i, count =0;

	printf("���ڸ� �Է��ϼ��� : ");
	gets(input);

	printf("���� ���ڿ� ���ο� ���� : ");
	scanf(" %c %c", &old, &new);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == old) {
			input[i] = new;
			count++;
		}
	}

	printf("\n��ȯ�� ��� ==> %s\n", input);

	//��ҹ��� ��ȯ
	for (i = 0; i < strlen(input); i++) {
		if ((input[i]>=65)&&(input[i]<=90)) {
			input[i] += 32;
			count++;
		}
		else if ((input[i] >= 97) && (input[i] <= 122)) {
			input[i] -= 32;
			count++;
		}

		//���ߺ�ȯ ����ó��
		if (input[i] == old) {
			count--;
		}
	}

	printf("�ѹ� �� ��ȯ�� ��� ==> %s\n", input);
	printf("��ȯ�� ���� ==> %d\n", count);
}