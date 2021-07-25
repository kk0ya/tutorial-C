//�߱�����
//��ǻ�Ͱ� �������� ���� 3���� ����
//�÷��̾�� 9���� ��ȸ���� ���� 3���� ������ ��� ���߸� �¸�, �� ���߸� �й�

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h> //����  
#include <time.h> //���尪 �ð����� �α�����

int answer[3];
int strike = 0, ball = 0;

void initiliaze()
{
    // ���� �迭 �ʱ�ȭ (���� �Լ��� ������ �� �ֱ�)
    srand((unsigned)time(NULL));
    int random;

    //�ߺ����� ����
    for (int i = 0; i < 3; i++) {
        random = rand() % 9 + 1;
        answer[i] = random;   
        if ((answer[i] == answer[i-1]) || (answer[i] == answer[i - 2])) {
            i--;
            continue;
        }

        //�������� Ȯ�ο�
        //printf(" %d", answer[i]);
    }
}

void get_input(int* player) {
    // �Է°��� �޾ƿ��� �Լ�
    scanf("%d %d %d", &player[0], &player[1], &player[2]);

    for (int i = 0; i < 3; i++) {
        //1~9�� ���ڸ� �Է�
        if ((player[i] < 1) || (player[i] > 9)) {
            printf("\n ��1���� 9 ������ ���ڸ� �Է����ּ���"
                   "\n���� 3���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.) : ");
            get_input(player);
        }

        //�ߺ��Ǵ� ���� ����
        for (int k = i - 1; k >= 0; k--) {
            if (player[i] == player[k]) {
                printf("\n ���ߺ��Ǵ� ���ڰ� �ֽ��ϴ�. �ٽ� �Է����ּ���"
                       "\n���� 3���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.) : ");
                get_input(player);
            }
        }
    }
}

void compare_answer_player(int* answer, int* player)
{
    strike = 0;
    ball = 0;
    //answer�� player �迭 ��
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
    //strike, ball ���
    printf("[���]��Ʈ����ũ : %d �� : %d",strike,ball);
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
    int player[3]; //����ڰ� ������ �Է��� �迭 ����  


    initiliaze();

    printf("1ȸ���� 9ȸ���� �õ��� �� �ֽ��ϴ�\n");
    for (int ct = 0; ct < 9; ++ct) {

        printf("\n[%dȸ�� ���ھ߱�]"
            "\n���� 3���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.) : ", ct + 1);

        get_input(player);

        compare_answer_player(answer, player);

        int victory = print_and_check_result();

        if (victory) {
            printf("\n\n*****�¸� �߽��ϴ�!*****\n");
            break;
        }

        if (ct == 8) {
            printf("9ȸ�� ������ �Ǿ����ϴ�. You lose!\n");
            break;
        }
    }
}