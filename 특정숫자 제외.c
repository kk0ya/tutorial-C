//1의 자리에 7이 들어가는 수를 제외한 수들을 출력
//1~ 200까지 가능

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int a, b;
	int i=0;

	while (1) {
		printf("=========================================================\n");
		printf("두 수를 입력하세요 : ");
		scanf("%d %d", &a, &b);

		if ((a >= 1 && a <= 200) && (b >= 10 && b <= 200) && (a < b)) {
			for (a; a <= b; a++) {
				if (a % 10 == 7) {
					continue;
				}
				printf("%4d", a);

				i++;

				if (i == 9) {
					printf("\n");
					i = 0;
				}
			}
		}

		else {
			printf("프로그램이 종료되었습니다\n");
			break;
		}
		printf("\n");
		printf("=========================================================\n");
	}
}