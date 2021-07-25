//키와 몸무게를 입력하면 책을 추천해주는 프로그램
//손님이 책을 구매할 때까지 계속 반복


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

int main() {
	int height, weight;
	int price;
	char choice;
	char book[30];

	for (; ; ) {
		printf("=========================================================================\n");
		printf("안녕하세요 손님 반갑습니다 :)  키와 몸무게를 입력하면 책을 추천해드려요!\n");
		printf("키 : ");
		scanf("%d", &height);
		printf("몸무게 : ");
		scanf("%d", &weight);

		if (height >= 170) {
			if (weight >= 50) {
				price = 9000;
				strcpy(book, "논리회로");
			}

			else if (weight < 50) {
				price = 7000;
				strcpy(book, "기구학");
			}
		}

		else if (height < 170) {
			if (weight >= 50) {
				price = 5000;
				strcpy(book, "전자회로");
			}

			else if (weight < 50) {
				price = 3000;
				strcpy(book, "공업수학");
			}
		}

		printf("%s는 %d원 입니다. 책을 구매 하시겠습니까?[y/n] : ",book,price);
		scanf(" %c", &choice);

		if (choice == 'y') {
			printf("구매해주셔서 감사합니다\n");
			break;
		}

		else {
			printf("네, 그럼 다음손님~~\n");
		}
		printf("=========================================================================\n");
	}
}