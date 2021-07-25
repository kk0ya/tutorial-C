//금액을 입력하면 500원, 100원, 50원, 10원으로 환전
//500원짜리가 몇 개 필요한지 물어보고 필요한 만큼 바꿔줌
//만약 500원짜리가 전체금액을 초과하면 가능한 최대의 갯수로 바꿔줌

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main() {
	int c500, c100, c50, c10;
	int money;
	
	printf("##교환할 돈은? : ");
	scanf("%d", &money);

	printf("##500원짜리 몇개 필요? : ");
	scanf("%d", &c500);

	if (c500 * 500 > money) {
		printf("##교환할 금액으로 %d개 못 바꿔드려요\n\n", c500);
		c500 = money / 500;
	}

	money = money - c500 * 500;

	c100 = money / 100;
	money = money % 100;

	c50 = money / 50;
	money = money % 50;

	c10 = money / 10;
	money = money % 10;

	printf("오백원짜리 : %d개\n", c500);
	printf("백원짜리 : %d개\n", c100);
	printf("오십원짜리 : %d개\n", c50);
	printf("십원짜리 : %d개\n", c10);
	printf("바꾸지 못한 잔돈 : %d원\n",money );
}