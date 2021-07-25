//특정문자를 다른문자로 변환 후 전체문자를 대소문자 변환

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	char input[100];
	char old, new;
	int i, count =0;

	printf("글자를 입력하세요 : ");
	gets(input);

	printf("기존 문자와 새로운 문자 : ");
	scanf(" %c %c", &old, &new);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == old) {
			input[i] = new;
			count++;
		}
	}

	printf("\n변환된 결과 ==> %s\n", input);

	//대소문자 변환
	for (i = 0; i < strlen(input); i++) {
		if ((input[i]>=65)&&(input[i]<=90)) {
			input[i] += 32;
			count++;
		}
		else if ((input[i] >= 97) && (input[i] <= 122)) {
			input[i] -= 32;
			count++;
		}

		//이중변환 예외처리
		if (input[i] == old) {
			count--;
		}
	}

	printf("한번 더 변환된 결과 ==> %s\n", input);
	printf("변환된 개수 ==> %d\n", count);
}