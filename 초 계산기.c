//�ʸ� �Է��ϸ� �ð�, ��, �ʷ� �ٲ㼭 ���

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int h, m, s;

	printf("##����� �ʴ�?");
	scanf("%d", &s);

	h = s / 3600;
	s = s % 3600;

	m = s / 60;
	s = s % 60;
	
	printf("%d�ð� %d�� %d��\n", h, m, s);
}