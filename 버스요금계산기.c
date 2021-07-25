//버스요금을 계산해주는 프로그램
//요금 : 어른 1200원, 어린이 1000원
//카드잔액을 다 쓸때까지 반복

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int card_money;
	int adult = 1200, kid = 1000;
	int sum;

	printf("버스요금 계산 프로그램입니다\n");
	printf("어른은 %d원, 어린이는 %d원입니다\n\n", adult, kid);

	printf("현재 카드잔액을 입력하세요 : ");
	scanf("%d", &card_money);
	
	while (1) {
		int adult_num, kid_num;

		printf("어른, 아이가 몇 명이나 탑승하나요? : ");
		scanf("%d %d", &adult_num, &kid_num);

		sum = (adult_num * adult) + (kid_num * kid);

		if (sum <= card_money) {
			card_money -= sum;
			printf("어른 : %d명, 아이 : %d명\n", adult_num, kid_num);
			printf("요금 : %d원, 남은 잔액 : %d\n\n", sum, card_money);
		}

		else {			
			printf("어른 : %d명, 아이 : %d명\n", adult_num, kid_num);
			printf("요금이 %d원 부족합니다\n",sum-card_money);
			printf("프로그램을 종료합니다\n");
			break;
		}
	}
}