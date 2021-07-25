//구조체를 활용한 학생관리 프로그램
//학생의 학번,이름, 국영수 점수 입력
//각 학생의 총점과 평균점수를 구한 뒤 평균점수 순으로 정렬

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

int cnt = 0; //학생 수

void input_data(student* pary); //학생 데이터 입력
void  calc_data(student* pary); //총점, 평균, 학점 계산
void print_data(student* pary); //출력
void  sort_data(student* pary); //평균 내림차순으로 정렬


int main() {
	student* ary;

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &cnt);

	ary = (student*)malloc(sizeof(student) * cnt);

	input_data(ary);
	calc_data(ary);
	
	printf("#평균점수 순서로 정렬 전 데이터 : \n");
	print_data(ary);
	sort_data(ary);
	printf("#평균점수 순서로 정렬 후 데이터 :\n");
	print_data(ary);

	free(ary);

	return 0;
}

void input_data(student* pary) {
	for (int i = 0; i < cnt; i++) {


		//점수 자동입력 (직접 입력하는 것이 귀찮아서 넣은거)
		//----------------------------------------------------------------//
		srand((unsigned)time(NULL));
		int random1, random2,random3;
		random1 = rand() % 51 + 50;
		random2 = rand() % 51 + 50;
		random3 = rand() % 51 + 50;
		//----------------------------------------------------------------//

		printf(">학번 : ");
		scanf("%d", &pary[i].num);
		printf(">이름 : ");
		scanf("%s", &pary[i].name);
		printf(">국어, 영어, 수학 점수 : ");

		//점수 자동입력
		//----------------------------------------------------------------//
		pary[i].kor = random1; pary[i].eng=random2; pary[i].mat=random3;
		printf("%d %d %d\n", pary[i].kor, pary[i].eng, pary[i].mat);
		//---------------------------------------------------------------//

		//scanf("%d %d %d", &pary[i].kor, &pary[i].eng, &pary[i].mat);   //점수 직접입력
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