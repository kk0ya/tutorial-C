//야구게임
//컴퓨터가 랜덤으로 숫자 3개를 생성
//플레이어는 9번의 기회동안 숫자 3개와 순서를 모두 맞추면 승리, 못 맞추면 패배
//난이도 조절함수 추가

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해

int answer[3];
int strike = 0, ball = 0;

int lev; //난이도조절(숫자 3개 or 4개)

void level() {
    int select;
    printf("난이도를 선택해주세요 <1> 초급 <2> 중급 : ");
    scanf("%d", &select);
    switch (select) {
    case 1 :
    case 2 :
        lev = select + 2;
        break;
    default :
        printf("***1 또는 2를 선택해주세요***\n");
        level();
        break;
    }
}

void initiliaze()
{
    // 정답 배열 초기화 (랜덤 함수로 임의의 값 넣기)
    srand((unsigned)time(NULL));
    int random;

    //중복숫자 방지
    for (int i = 0; i < lev; i++) {
        random = rand() % 9 + 1;
        answer[i] = random;
        for (int k = 1; k < lev; k++) {
            if (answer[i] == answer[i - k]) {
                i--;
            }
        }
    }

    //컴퓨터의 숫자확인
    /*for (int i = 0; i < lev; i++) {
        printf(" %d", answer[i]);
    }*/
    printf("\n");    
}

void get_input(int* player) {
    // 입력값을 받아오는 함수
    for (int i = 0; i < lev; i++) {
        scanf("%d", &player[i]);
    }
    

    for (int i = 0; i < lev; i++) {
        //1~9의 숫자만 입력
        if ((player[i] < 1) || (player[i] > 9)) {
            printf("\n ※1부터 9 사이의 숫자를 입력해주세요"
                   "\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ",lev);
            get_input(player);
        }

        //중복되는 숫자 방지
        for (int k = i - 1; k >= 0; k--) {
            if (player[i] == player[k]) {
                printf("\n ※중복되는 숫자가 있습니다. 다시 입력해주세요"
                       "\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ",lev);
                get_input(player);
            }
        }
    }
}

void compare_answer_player(int* answer, int* player)
{
    strike = 0;
    ball = 0;
    //answer와 player 배열 비교
    for (int i = 0; i < lev; i++) {
        for (int k = 0; k < lev; k++) {
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

int print_and_check_result() {
    //strike, ball 프린트
    printf("[결과]스트라이크 : %d 볼 : %d",strike,ball);
    if (strike + ball == 0) {
        printf("   out!!!");
    }
    printf("\n");

    // victory or ~ing
    if(strike == lev){
        return 1;
    }
    else {
        return 0;
    }
}



void main()
{
    level(&lev); //레벨설정

    int player[3]; //사용자가 정답을 입력할 배열 생성  

    initiliaze();

    printf("1회에서 9회까지 시도할 수 있습니다\n");
    for (int ct = 0; ct < 9; ++ct) {

        printf("\n[%d회차 숫자야구]"
            "\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ", ct + 1,lev);

        get_input(player);

        compare_answer_player(answer, player);

        int victory = print_and_check_result();

        if (victory) {
            printf("\n\n*****승리 했습니다!*****\n");
            break;
        }

        if (ct == 8) {
            printf("9회가 마무리 되었습니다. You lose!\n");
            break;
        }
    }
}
