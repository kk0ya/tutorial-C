//����ü�� Ȱ���� �л����� ���α׷�

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <malloc.h>

struct student {
	char name[10];
	int age;
};

void get_input(int cnt, struct student* s);

int main() {
	struct student* s;
	int cnt, i;

	printf("�Է��� �л� �� : ");
	scanf("%d", &cnt);

	s = (struct student*)malloc((sizeof(struct student)) * cnt);
	get_input(cnt,s);

	printf("\n\n--�л����--\n\n");
	for (i = 0; i < cnt; i++) {
		printf("�̸� : %s, ���� : %d\n", s[i].name, s[i].age);
	}

	free(s);
}

void get_input(int cnt, struct student *s) {
	for (int i = 0; i < cnt; i++) {
		printf("�̸��� ���� �Է� : ");
		scanf("%s %d", &(s + i)->name, &(s + i)->age);
	}
}
