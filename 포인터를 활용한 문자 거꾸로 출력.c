//포인터를 이용한 문자 거꾸로 출력

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

	printf("문자열을 입력하세요 : ");
	scanf("%s", s);

	p = s;
	len = strlen(s);

	printf("내용을 거꾸로 출력 ==> ");
	
	for (i = 0; i < len; i++) {
		printf("%c", *(p+len-(i+1)));
	}
	printf("\n");
}