//포인터를 이용한 거품정렬(bubble sort)
//오름차순 내림차순 정렬

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	int s[10];
	int tmp;
	int i, k;
	int up_down;
	int* p;

	printf("\t< 0부터 9 사이의 숫자를 한 번씩만 입력해주세요 >\n");

	//데이터 입력
	for (i = 0; i < 10; i++) {
		printf(" s[%d] 데이터 : ", i);
		scanf("%d", &s[i]);

		//0~9의 숫자만 입력
		if ((s[i] < 0) || (s[i] > 9)) {
			printf("\n ※0부터 9 사이의 숫자를 입력해주세요\n");
			i--;
		}
		
		//중복되는 숫자 방지
		for (k = i-1; k >= 0; k--) {
			if (s[i] == s[k]) {
				printf("\n ※중복되는 숫자( %d )가 있습니다. 다시 입력해주세요\n",s[i]);
				i--;
			}
		}
	}

	p = s;

	//정렬 전 배열
	printf("\n\t정렬 전 배열 s ==> ");
	for (i = 0; i < 10; i++) {
		printf("%2d", *(p + i));
	}
	
	//정렬 방식 선택
	do {
		printf("\n\n 정렬 방식을 선택하세요 - 오름차순 < 1 >  내림차순 < 2 > \n");
		printf(" 데이터 정렬 : ");
		scanf("%d", &up_down);

		switch (up_down) {
		case 1: //오름차순
			for (i = 0; i < 9; i++) {
				for (k = i + 1; k < 10; k++) {
					if (*(p + i) > *(p + k)) {
						tmp = *(p + i);
						*(p + i) = *(p + k);
						*(p + k) = tmp;
					}
				}
			}
			break;

		case 2: //내림차순
			for (i = 0; i < 9; i++) {
				for (k = i + 1; k < 10; k++) {
					if (*(p + i) < *(p + k)) {
						tmp = *(p + i);
						*(p + i) = *(p + k);
						*(p + k) = tmp;
					}
				}
			}
			break;
		default:
			printf("\n1 또는 2를 입력해주세요!\n");
		}
	} while (up_down > 2);

	//정렬 후 배열
	printf("\n\t정렬 후 배열 s ==> ");
	for (i = 0; i < 10; i++) {
		printf("%2d", *(p + i));
	}
	printf("\n");
}