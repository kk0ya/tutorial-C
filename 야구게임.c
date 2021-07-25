//야구게임
//컴퓨터가 랜덤으로 숫자 3개를 생성
//플레이어는 9번의 기회동안 숫자 3개와 순서를 모두 맞추면 승리, 못 맞추면 패배
//난이도 조절함수 추가 ==> 동적할당 활용
//재시작함수 추가
//사용자의 데이터를 저장,불러오기 기능 추가

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해
#include <windows.h>

FILE* userdata;

int* answer;											//정답
int* player;											//입력
int trial = 1;											//게임횟수
int win = 0, lose = 0;								    //승패
int strike = 0, ball = 0;

int level();											//난이도 조절
int print_and_check_result(int level_select);			//승패

void start();											//새로시작 or 불러오기
void initiliaze();										//정답 생성
void get_input(int* player);						    //정답 입력
void compare_answer_player(int* answer, int* player);   //정답 비교
void regame();											//재시작

void main()
{
	start(); 
	printf("******반갑습니다 %d번째 야구게임을 시작합니다******\n", trial);
	printf("******플레이어는 현재까지 %d승 %d패 입니다******\n\n", win, lose);
	Sleep(2000);

	int level_select = level(); //난이도조절
	initiliaze(level_select);

	player = (int*)malloc(sizeof(int) * level_select);

	printf("\n******1회에서 9회까지 시도할 수 있습니다******\n");

	for (int ct = 0; ct < 9; ++ct) {
		printf("  [%d회차 숫자야구]\n", ct + 1);

		get_input(level_select,player);
		compare_answer_player(answer, player, level_select);
		int victory = print_and_check_result(level_select);

		if (victory) {
			printf("\n******승리 했습니다!******\n\n");
			win++;
			break;
		}

		if (ct == 8) {
			printf("9회가 마무리 되었습니다. You lose!\n    정답 : ");
			for (int i = 0; i < level_select; i++) {
				printf(" %d", answer[i]);
			}
			printf("\n");
			lose++;
			break;
		}
	}
	free(answer);
	free(player);

	trial++; Sleep(1000);

	regame();
}

void start() {
	int a;

	do {
		system("cls");
		printf("<1>새로시작 <2>이어하기 <3>불러오기\n");
		a = getch();
		switch (a)
		{
		case '1':
			printf("******게임을 새로 시작합니다******\n");
			userdata = fopen("c:\\temp\\userdata.txt", "w+");
			fclose(userdata);
			trial = 1; win = lose = 0;
			break;
		case '2':
			if (trial == 1) {
				printf("******저장된 데이터가 없으므로 게임을 새로 시작합니다******\n");
			}
			else {
				printf("******게임을 이어서 합니다******\n");
			}
			break;
		case '3':
			userdata = fopen("c:\\temp\\userdata.txt", "r");
			if (userdata == NULL) {
				printf("******저장된 데이터가 없으므로 게임을 새로 시작합니다******\n");
				userdata = fopen("c:\\temp\\userdata.txt", "w+");				
			}
			else {
				printf("******저장된 데이터를 불러옵니다******\n");
			}
			fscanf(userdata, "%d, %d, %d", &trial, &win, &lose);
			fclose(userdata);
			break;
		}
	} while ((a < '1') || (a > '3'));
}

int level() {
	int a;
	system("cls");
	printf("※난이도를 선택해주세요\n몇개의 숫자를 생성하나요? <2>2개 <3>3개 <4>4개\n ");
	a = getch();
	switch (a) {
	case '2':
	case '3':
	case '4':
		return a-48;
		break;
	default:
		level();
		break;
	}
}

void initiliaze(int level_select)
{
	// 정답 배열 초기화 (랜덤 함수로 임의의 값 넣기)
	srand((unsigned)time(NULL));
	int random;
	answer = (int*)malloc(sizeof(int) * level_select);

	//중복숫자 방지
	for (int i = 0; i < level_select; i++) {
		random = rand() % 9 + 1;
		answer[i] = random;
		for (int k = 1; k < level_select; k++) {
			if (answer[i] == answer[i - k]) {
				i--;
			}
		}
	}

	//컴퓨터의 숫자확인
	for (int i = 0; i < level_select; i++) {
		printf(" %d", answer[i]);
	}	printf("\n");
}

void get_input(int level_select, int* player) {
	// 입력값을 받아오는 함수
	for (int i = 0; i < level_select; i++) {
		printf("\n  %d번째 숫자 입력 : ", i + 1);
		player[i] = getche() - 48;

		//1~9의 숫자만 입력
		if ((player[i] < 1) || (player[i] > 9)) {
			printf("\n ※1부터 9 사이의 숫자를 입력해주세요\n");
			i--;
		}

		//중복되는 숫자 방지
		for (int k = i - 1; k >= 0; k--) {
			if (player[i] == player[k]) {
				printf("\n ※중복되는 숫자가 있습니다. 다시 입력해주세요\n");
				i--;
			}
		}
	}
}

void compare_answer_player(int* answer, int* player, int level_select)
{
	strike = 0;
	ball = 0;
	//answer와 player 배열 비교
	for (int i = 0; i < level_select; i++) {
		for (int k = 0; k < level_select; k++) {
			if (answer[i] == player[k]) {
				if (i == k) {
					strike++;
				}
				else {
					ball++;
				}
			}
		}
	}
}

int print_and_check_result(int level_select) {
	//strike, ball 프린트
	printf("\n   [결과]스트라이크 : %d 볼 : %d", strike, ball);
	if (strike + ball == 0) {
		printf("   out!!!");
	}   printf("\n\n");

	// victory or ~ing
	if (strike == level_select) {
		return 1;
	}
	else {
		return 0;
	}
}

void regame() {
	int re;
	int save;

	do {
		system("cls");
		printf("게임을 계속 하시겠습니까?\n <1>계속하기 <2>종료하기\n");
		re = getch();
		switch (re) {
		case '1':
			printf("******게임을 계속합니다******\n\n");
			Sleep(1000);
			main();
			break;
		case '2':
			do {
				system("cls");
				printf("플레이어는 현재까지 %d승 %d패 입니다\n", win, lose);
				printf("게임을 저장하시겠습니까?\n <1>예 <2>아니요 <3>뒤로\n");
				save = getch();
				switch (save) {
				case '1':
					printf("******게임을 저장 후 종료합니다******\n");
					userdata = fopen("c:\\temp\\userdata.txt", "r+");
					fprintf(userdata, "%d, %d, %d", trial, win, lose);
					fclose(userdata);
					break;
				case '2':
					printf("******게임을 저장하지 않고 종료합니다******\n");
					break;
				case '3':
					regame();
					break;
				};
			} while ((save < '1') || (save > '3'));
			break;
		}
	} while ((re != '1') && (re != '2'));
}
