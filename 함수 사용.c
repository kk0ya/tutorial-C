//함수 활용

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void input_data();
void swap_data();
void print_data(int a, int b);

int a, b;

int main() {
	input_data();
	swap_data();
	print_data(a, b);
}

void input_data() {
	printf("두 정수 입력 : ");
	scanf("%d %d", &a, &b);
}

void swap_data() {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b) {
	printf("두 정수 출력 : %d %d", a, b);
}