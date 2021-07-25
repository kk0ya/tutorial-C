//����ü�� Ȱ���� �л����� ���α׷�
//�л��� �й�,�̸�, ������ ���� �Է�
//�� �л��� ������ ��������� ���� �� ������� ������ ����

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

typedef struct {
	int num;
	char name[20];
	int kor, eng, mat;
	int tot;
	float avg;
	char grade;
}student;

int cnt = 0; //�л� ��

void input_data(student* pary); //�л� ������ �Է�
void  calc_data(student* pary); //����, ���, ���� ���
void print_data(student* pary); //���
void  sort_data(student* pary); //��� ������������ ����


int main() {
	student* ary;

	printf("�л� ���� �Է��ϼ��� : ");
	scanf("%d", &cnt);

	ary = (student*)malloc(sizeof(student) * cnt);

	input_data(ary);
	calc_data(ary);
	
	printf("#������� ������ ���� �� ������ : \n");
	print_data(ary);
	sort_data(ary);
	printf("#������� ������ ���� �� ������ :\n");
	print_data(ary);

	free(ary);

	return 0;
}

void input_data(student* pary) {
	for (int i = 0; i < cnt; i++) {


		//���� �ڵ��Է� (���� �Է��ϴ� ���� �����Ƽ� ������)
		//----------------------------------------------------------------//
		srand((unsigned)time(NULL));
		int random1, random2,random3;
		random1 = rand() % 51 + 50;
		random2 = rand() % 51 + 50;
		random3 = rand() % 51 + 50;
		//----------------------------------------------------------------//

		printf(">�й� : ");
		scanf("%d", &pary[i].num);
		printf(">�̸� : ");
		scanf("%s", &pary[i].name);
		printf(">����, ����, ���� ���� : ");

		//���� �ڵ��Է�
		//----------------------------------------------------------------//
		pary[i].kor = random1; pary[i].eng=random2; pary[i].mat=random3;
		printf("%d %d %d\n", pary[i].kor, pary[i].eng, pary[i].mat);
		//---------------------------------------------------------------//

		//scanf("%d %d %d", &pary[i].kor, &pary[i].eng, &pary[i].mat);   //���� �����Է�
		printf("\n");
	}
}

void calc_data(student* pary) {
	for (int i = 0; i < cnt; i++) {
		pary[i].tot = pary[i].kor + pary[i].eng + pary[i].mat;
		pary[i].avg = pary[i].tot / 3.00;

		if (pary[i].avg >= 90) {
			pary[i].grade = 'A';
		}

		else if (pary[i].avg >= 80) {
			pary[i].grade = 'B';
		}

		else if (pary[i].avg >= 70) {
			pary[i].grade = 'C';
		}

		else {
			pary[i].grade = 'F';
		}
	}
}

void  print_data(student* pary) {
	for (int i = 0; i < cnt; i++) {
		printf("%3d %3s %3d %3d %3d %4d %6.2f %3c\n",
			pary[i].num, pary[i].name, pary[i].kor, pary[i].eng, pary[i].mat, pary[i].tot, pary[i].avg, pary[i].grade);
	}
}

void  sort_data(student* pary) {
	student temp;

	for (int i = 0; i < cnt; i++) {
		for (int k = 0; k < cnt-1; k++) {
			if (pary[i].avg > pary[k].avg) {
				temp = pary[i];
				pary[i] = pary[k];
				pary[k] = temp;
			}
		}
	}
}