//야구게임
//컴퓨터가 랜덤으로 숫자 3개를 생성
//플레이어는 9번의 기회동안 숫자 3개와 순서를 모두 맞추면 승리, 못 맞추면 패배

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해

int answer[3];
int strike = 0, ball = 0;

void initiliaze()
{
    // 정답 배열 초기화 (랜덤 함수로 임의의 값 넣기)
    srand((unsigned)time(NULL));
    int random;

    //중복숫자 방지
    for (int i = 0; i < 3; i++) {
        random = rand() % 9 + 1;
        answer[i] = random;   
        if ((answer[i] == answer[i-1]) || (answer[i] == answer[i - 2])) {
            i--;
            continue;
        }

        //생성숫자 확인용
        //printf(" %d", answer[i]);
    }
}

void get_input(int* player) {
    // 입력값을 받아오는 함수
    scanf("%d %d %d", &player[0], &player[1], &player[2]);

    for (int i = 0; i < 3; i++) {
        //1~9의 숫자만 입력
        if ((player[i] < 1) || (player[i] > 9)) {
            printf("\n ※1부터 9 사이의 숫자를 입력해주세요"
                   "\n숫자 3개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ");
            get_input(player);
        }

        //중복되는 숫자 방지
        for (int k = i - 1; k >= 0; k--) {
            if (player[i] == player[k]) {
                printf("\n ※중복되는 숫자가 있습니다. 다시 입력해주세요"
                       "\n숫자 3개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ");
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
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
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
    //strike, ball 출력
    printf("[결과]스트라이크 : %d 볼 : %d",strike,ball);
    if (strike + ball == 0) {
        printf("   out!!!");
    }
    printf("\n");

    // victory or ~ing
    if(strike == 3){
        return 1;
    }
    else {
        return 0;
    }
}



void main()
{
    int player[3]; //사용자가 정답을 입력할 배열 생성  


    initiliaze();

    printf("1회에서 9회까지 시도할 수 있습니다\n");
    for (int ct = 0; ct < 9; ++ct) {

        printf("\n[%d회차 숫자야구]"
            "\n숫자 3개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ", ct + 1);

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
