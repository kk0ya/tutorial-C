//문자를 입력하면 문자순서를 거꾸로 출력

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	char str[10] = "";
	int i;

	printf("문자열을 입력 ==> ");
	scanf("%s", str);

	for (i = sizeof(str) - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}