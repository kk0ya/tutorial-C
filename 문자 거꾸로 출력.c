//���ڸ� �Է��ϸ� ���ڼ����� �Ųٷ� ���

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	char str[10] = "";
	int i;

	printf("���ڿ��� �Է� ==> ");
	scanf("%s", str);

	for (i = sizeof(str) - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}