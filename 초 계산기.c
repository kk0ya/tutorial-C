//초를 입력하면 시간, 분, 초로 바꿔서 출력

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int h, m, s;

	printf("##계산할 초는?");
	scanf("%d", &s);

	h = s / 3600;
	s = s % 3600;

	m = s / 60;
	s = s % 60;
	
	printf("%d시간 %d분 %d초\n", h, m, s);
}