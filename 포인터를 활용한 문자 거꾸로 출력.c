//�����͸� �̿��� ���� �Ųٷ� ���

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	char s[100];
	char* p;
	int i;
	int len;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", s);

	p = s;
	len = strlen(s);

	printf("������ �Ųٷ� ��� ==> ");
	
	for (i = 0; i < len; i++) {
		printf("%c", *(p+len-(i+1)));
	}
	printf("\n");
}